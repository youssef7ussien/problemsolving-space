[CmdletBinding()]
param (
    [Parameter(Mandatory)]
    [ValidateSet("CF", "UVA", "SPOJ", "CSES", "ATC", "TEMP", 'LeetCode', 'LTC')]
    [string]$OnlineJudge,
    [Parameter(Mandatory)]
    [string]$ProblemCode,
    [Parameter(Mandatory)]
    [string]$ProblemName,

    [Switch]$IOFiles,
    [Switch]$NoTempCode,
    [Switch]$NoNamedFile,
    [Switch]$NoConfirm
)

DynamicParam {
    if($OnlineJudge -in 'CSES', 'LeetCode', 'LTC') {
        $paramAttribute = [System.Management.Automation.ParameterAttribute]@{
            Mandatory = $true
        }

        $attributeCollection = [System.Collections.ObjectModel.Collection[System.Attribute]]::new()
        $attributeCollection.Add($paramAttribute)

        $paramDictionary = [System.Management.Automation.RuntimeDefinedParameterDictionary]::new()
        $ExtraParams = [System.Management.Automation.RuntimeDefinedParameter]::new(
            'ExtraParams', [string], $attributeCollection
        )

        $paramDictionary.Add('ExtraParams', $ExtraParams)
        return $paramDictionary
    }
}

begin {
    $OnlineJudge = $OnlineJudge.trim()
    if($OnlineJudge -notin 'LeetCode', 'LTC' ) {
        $OnlineJudge = $OnlineJudge.ToUpper()
    }

    $ProblemCode = $ProblemCode.Trim().ToUpper()
    $ProblemName = $ProblemName.Trim()

    $parentFolder = "Problems Solutions"
    $BinFolder = "bin"
    $IOFolder = "samples"
    $fullPath = "$(Get-Location)\$parentFolder\"
    $fileName = "main.cpp"
    $tempCodeDir = "$(Get-Location)\Templates"
    $tempCodePath = "$tempCodeDir\temp_code.cpp"
    $LeetCodeTempPath = "$tempCodeDir\leetcode_temp_code.cpp"
    $ExtraParams = $PSBoundParameters['ExtraParams']
    $Judges = @{
        CF       = "Codeforces";
        UVA      = "UVA Online Judge";
        SPOJ     = "SPOJ - Sphere Online Judge";
        HR       = "HackerRank";
        CSES     = "CSES";
        LeetCode = "LeetCode";
        AtCoder  = "AtCoder";
        TEMP     = "Uncategorized";
    }
}

process {
    if($ProblemName.IndexOfAny([System.IO.Path]::GetInvalidFileNameChars()) -ne -1) {
        Write-Host "File name `"$filename`" contains invalid characters"
        return
    }

    if (-Not (Test-Path $fullPath)) {
        Write-Output "Invalid path, `'$parentFolder`' directory not found."
        return
    }

    function Get-VolumeNumber($Code, [int]$trailing = 3) {
        $Code = ([math]::floor(([int]$Code) / 100))
        return  "Volume $(([string]$Code).PadLeft($trailing, '0'))"
    }
    
    function New-File() {
        mkdir $fullPath/$IOFolder, $fullPath/$BinFolder
        
        $FileContent = ""
        $IOFilesPrefixName = "$($IOFolder)\$($OnlineJudge)_$($ProblemCode)"

        if (!$NoTempCode) {
            $Header = "/**`n * Title: `"$($ProblemName)`", $($Judges[$OnlineJudge]) problem. `n * Date: $(Get-Date -Format D) `n *`n */`n"
            
            if($OnlineJudge -in 'LeetCode', 'LTC') {
                $tempCodeContent = Set-LeetCodeContent
            }
            else {
                $tempCodeContent = (Get-content -Path $tempCodePath -Raw)
            }
            
            if($IOFiles) {
                # $tempCodeContent = $tempCodeContent.Replace(
                #     'input.in', "$($IOFilesPrefixName.Replace('\', '\\')).in").Replace(
                #         'output.out', "$($IOFilesPrefixName.Replace('\', '\\')).out")
                
                New-Item -Path $fullPath -Name "$($IOFilesPrefixName).in" -ItemType File
                New-Item -Path $fullPath -Name "$($IOFilesPrefixName).out" -ItemType File
                New-Item -Path $fullPath -Name "$($IOFilesPrefixName)_origin.out" -ItemType File
            }
                
            $FileContent = $Header + $tempCodeContent
        }
        
        New-Item -Path $fullPath -Name $fileName -ItemType File -Value $FileContent
        code.cmd "$fullPath\$fileName"
        
        # if ($IOFiles) {
        #     code.cmd -d "$($fullPath)\$($IOFilesPrefixName)_origin.out" "$($fullPath)\$($IOFilesPrefixName).out"
        # }
    }

    function Set-LeetCodeContent() {
            $tempCodeContent = (Get-content -Path $LeetCodeTempPath -Raw)

            $tempCodeContent = $tempCodeContent.Replace('void functionName() {', $ExtraParams)
            
            $variableNames = $ExtraParams -replace ".*\((.*)\).*", '$1'
            $variableNames = ($variableNames -replace "const ?", '') -Replace " ?&", ' '
            $variableNames =  [regex]::Split($variableNames, ", ?")
            
            $tempCodeContent = $tempCodeContent.Replace('// variableName', $variableNames + "" -join ";`n`t")
            $tempCodeContent = $tempCodeContent.Replace('solution.functionName();', 
                "solution.$($ExtraParams -replace  ".* (.*)\(.*\).*", '$1')($($variableNames -replace ".* (.*)", '$1' -join ', '));"
            )
            
            return $tempCodeContent
    }

    switch ($OnlineJudge) {
        { $_ -in 'Codeforce', 'CF' } {
            $fullPath += $Judges['CF'] + "\"
            
            if (-Not (Test-Path $fullPath)) {
                Write-Output "Invalid $($Judges['CF']) path, You should found `'$parentFolder\$($Judges['CF'])`' directory."
                return
            }

            if ($ProblemCode -match '^[0-9]{1,4}[a-zA-z]{1}[1-9a-zA-Z]?$') {
                $problemNumber, $problemChar = $ProblemCode, $ProblemCode

                $problemNumber = $problemNumber -replace '[A-Za-z]{1}[A-Za-z1-9]?$', ''
                $problemChar = $problemChar -replace '^[0-9]+', ''
                
                $folderName = $problemNumber + $problemChar + " - " + $ProblemName
                
                $fullPath += $problemChar[0] + "\" + (Get-VolumeNumber -Code $problemNumber) + "\" + $folderName

                if (!$NoNamedFile) {
                    $fileName = "CF_" + $problemNumber + $problemChar + ".cpp"
                }
            }
            else {
                Write-Output "Problem Code `"$ProblemCode`" is not valid."
                return
            }
            Break
        }
        { $_ -eq 'UVA' } {
            $fullPath += $Judges['UVA'] + "\"
            
            if (-Not (Test-Path $fullPath)) {
                Write-Output "Invalid $($Judges['UVA']) path, You should found `'$parentFolder\$($Judges['UVA'])`' directory."
                return
            }

            if ($ProblemCode -match '^[0-9]{1,6}$') {
                $folderName = $ProblemCode + " - " + $ProblemName
                $fullPath += (Get-VolumeNumber -Code $ProblemCode) + "\" + $folderName
                
                if (!$NoNamedFile) {
                    $fileName = "UVA_" + $ProblemCode + ".cpp"
                }
            }
            else {
                Write-Output "Problem Code `"$ProblemCode`" is not valid."
                return
            }
            
            Break
        }
        { $_ -eq 'SPOJ' } {
            $fullPath += $Judges['SPOJ'] + "\"
            
            if (-Not (Test-Path $fullPath)) {
                Write-Output "Invalid $($Judges['SPOJ']) path, You should found `'$parentFolder\$($Judges['SPOJ'])`' directory."
                return
            }
            
            $folderName = $ProblemCode + " - " + $ProblemName
            $fullPath += $folderName
            
            if (!$NoNamedFile) {
                $fileName = "SPOJ_" + $ProblemCode + ".cpp"
            }

            Break
        }
        { $_ -eq 'CSES' } {
            $fullPath += $Judges['CSES'] + "\"
            
            if (-Not (Test-Path $fullPath)) {
                Write-Output "Invalid $($Judges['CSES']) path, You should found `'$parentFolder\$($Judges['CSES'])`' directory."
                return
            }

            if ($ProblemCode -match '^[0-9]{1,6}$') {
                $fullPath += $PSBoundParameters.ExtraParams + "\" + $ProblemCode + " - " + $ProblemName

                if (!$NoNamedFile) {
                    $fileName = "CSES_" + $ProblemCode + ".cpp"
                }
            }
            else {
                Write-Output "Problem Code `"$ProblemCode`" is not valid."
                return
            }
            
            Break
        }
        { $_ -in 'LeetCode', 'LTC' } {
            $fullPath += $Judges['LeetCode'] + "\"
            
            if (-Not (Test-Path $fullPath)) {
                Write-Output "Invalid $($Judges['LeetCode']) path, You should found `'$parentFolder\$($Judges['LeetCode'])`' directory."
                return
            }

            if ($ProblemCode -match '^[0-9]{1,6}$') {
                $folderName = $ProblemCode + " - " + $ProblemName
                $fullPath += (Get-VolumeNumber -Code $ProblemCode) + "\" + $folderName
                
                if (!$NoNamedFile) {
                    $fileName = "LeetCode_" + $ProblemCode + ".cpp"
                }
            }
            else {
                Write-Output "Problem Code `"$ProblemCode`" is not valid."
                return
            }
            
            Break
        }
        { $_ -in 'ATC', 'AtCoder' } {
            $fullPath += $Judges['AtCoder'] + "\"
            
            if (-Not (Test-Path $fullPath)) {
                Write-Output "Invalid $($Judges['AtCoder']) path, You should found `'$parentFolder\$($Judges['AtCoder'])`' directory."
                return
            }
            
            if($ProblemCode -notmatch '^[aA][BHGbhg][cC][0-9]{3}_[a-zA-Z]$') {
                Write-Output "Problem Code `"$ProblemCode`" is not valid."
                return
            }
        
            $fullPath += $fullPath + "\" +  + "\" + $ProblemCode + " - " + $ProblemName

            if (!$NoNamedFile) {
                $fileName = "_" + $ProblemCode + ".cpp"
            }
            
            Break
        }
        { $_ -eq 'TEMP' } {
            $fullPath += $Judges['TEMP'] + "\"
            
            if (-Not (Test-Path $fullPath)) {
                Write-Output "Invalid $($Judges['TEMP']) path, You should found `'$parentFolder\$($Judges['TEMP'])`' directory."
                return
            }

            $folderName = $ProblemCode + " - " + $ProblemName
            $fullPath += $folderName
            
            if (!$NoNamedFile) {
                $fileName = $ProblemCode + ".cpp"
            }

            Break
        }
        Default {
            Write-Output "Online-Judge `"$_`" is not supported"
            return
        }
    }

    if (-Not (Test-Path $fullPath)) {
        if ($NoConfirm) {
            New-File
        }
        else {
            $reply = Read-Host -Prompt "Create file at $($fullPath)? [Y/n]"
            
            if ($reply -eq "y") {
                New-File
            }
            else {
                Write-Output "Cancelled."
                return
            }
        }
    }
    else {
        Write-Output "This problem already exist."
        return
    }
}
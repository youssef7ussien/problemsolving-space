#!/usr/bin/env bash

# version
# declare -r neoproblem_version="0.0.1"
declare -r MAIN_FOLDER="$PROBLEM_SOLVING/ProblemSolving"
declare -r TEMPLATE_FOLDER="$PROBLEM_SOLVING/Templates"
declare -r BIN_FOLDER="bin"
declare -r IO_FOLDER="samples"
declare -r -A JUDGE_NAMES='([CF]="Codeforces")'

usage() {
    return
}

die() {
    printf "[%s]: %s\n" "$(date +'%Y-%m-%dT%H:%M:%S%z')" "$*" >&2
    exit 1
}

create_problem_file() {
    mkdir -p "$folder_path/"{"$IO_FOLDER","$BIN_FOLDER"}

    local temp
    temp="\/**\n * Title: \"$problem_name\", ${JUDGE_NAMES[$online_judge]} problem. \n * Date: $(date '+%A, %d %B %Y') \n *\n *\/\n"

    case "$lang_program" in
        "cpp")
            cat "$TEMPLATE_FOLDER/temp_code.cpp" > "$folder_path/${1}.cpp"
            sed -i "1s/^/$temp/" "$folder_path/${1}.cpp"
            ;;
        "java")
            cat "$TEMPLATE_FOLDER/temp_code.java" > "$folder_path/${1}.java"
            sed -i "1s/^/$temp/" "$folder_path/${1}.java"
            sed -i -E "s/^(public class) temp_code (\{)/\1 ${1} \2/" "$folder_path/${1}.java"
            ;;
    esac

}

get_cf_info() {
    local cf_api="https://codeforces.com/api/contest.standings?contestId=$problem_number&from=1&count=1&showUnofficial=false"

    local cf_json
    if ! cf_json=$(curl "$cf_api" -s); then
        die "ERROR: internet connection failed."
    fi

    if ! problem_tag=$( jq -r '.result.contest.name' <<<"$cf_json"); then
        die 'ERROR: failed problem id.'
    fi

    if ! problem_name=$( jq -r ".result.problems[] | select(.index == \"$problem_char\").name" <<<"$cf_json"); then
        die 'ERROR: failed problem id.'
    fi

    [[ -z "$problem_name" || -z "$problem_tag" ]] && die "ERROR: failed broblem code."
}

new_cf_problem() {
    [ ! -d "$folder_path" ] && die "Invalid Codeforces path. You should create '$folder_path' directory."

    if [[ ! "$problem_code" =~ ^[1-9][0-9]{1,3}[A-Z]{1}[1-9A-Z]?$ ]]; then
        die "ERROR: Problem code '$problem_code' is not valid for codeforces problems."
    fi

    local problem_number=$( grep -oE '^[0-9]*' <<<"$problem_code" )
    local problem_char=$( grep -oE '[A-Z].*' <<<"$problem_code" )

    [[ -z "$problem_name" || -z "$problem_tag" ]] && get_cf_info

    local folder_name="$problem_number$problem_char - $problem_name"

    problem_tag=$(tr '/\\|<>:"*?' '_' <<<"$problem_tag")

    local cf_div=
    case "$problem_tag" in
        *"Global"*) cf_div="Codeforces Global Rounds" ;;
        *"Educational"*) cf_div="Codeforces Educational Rounds" ;;
        *"Beta Round"*) cf_div="Codeforces Beta Rounds" ;;
        *"Div. 1 + Div. 2"*) cf_div="Codeforces Rounds (Div. 1 + Div. 2)" ;;
        *"Div. 1"*) cf_div="Codeforces Rounds (Div. 1)" ;;
        *"Div. 2"*) cf_div="Codeforces Rounds (Div. 2)" ;;
        *"Div. 3"*) cf_div="Codeforces Rounds (Div. 3)" ;;
        *"Div. 4"*) cf_div="Codeforces Rounds (Div. 4)" ;;
        *) cf_div="Codeforces Unrated Rounds" ;;
    esac

    folder_path+="/Codeforces/$cf_div/$problem_tag/$folder_name"
    create_problem_file "CF_$problem_number$problem_char"
}

main() {
    if [[ -z $1 ]]; then
        printf "No command spacified\n\n"
        usage
        exit 1
    fi

    local online_judge
    local problem_code
    local problem_name
    local problem_tag
    local lang_program
    local folder_path="$MAIN_FOLDER"
    # local io_files=true
    # local template_code=true
    # local force=true

    while :; do
        case "$1" in
            -h|--help)
                usage ; exit
                ;;
            -j)
                if [[ "$2" && "${2^^}" == @("CF"|"UVA"|"SPOJ"|"CSES"|"TEMP") ]]; then
                    online_judge="${2^^}"
                    shift
                else
                    die 'ERROR: "-j" requires an online judge name.'
                fi
                ;;
            -c)
                if [[ "$2" ]]; then
                    problem_code="${2^^}"
                    shift
                else
                    die 'ERROR: "-c" requires a problem code.'
                fi
                ;;
            -n)
                if [[ "$2" ]]; then
                    problem_name="$2"
                    shift
                else
                    die 'ERROR: "-n" requires a problem name.'
                fi
                ;;
            -t)
                if [[ "$2" ]]; then
                    problem_tag="$2"
                    shift
                else
                    die 'ERROR: "-t" requires a problem tag.'
                fi
                ;;
            -l)
                if [[ "$2" && "${2,,}" == @("cpp"|"java") ]]; then
                    lang_program="${2,,}"
                    shift
                else
                    die 'ERROR: "-l" requires a programming language.'
                fi
                ;;
            *)
                break ;;
        esac

        shift
    done

    [ -z "$online_judge" ] && die "ERROR: requires -j option."
    [ -z "$problem_code" ] && die "ERROR: requires -c option."
    [ -z "$lang_program" ] && lang_program="cpp"

    case "$online_judge" in
        "CF")
            new_cf_problem
            ;;
    esac
    return
}

main "$@"

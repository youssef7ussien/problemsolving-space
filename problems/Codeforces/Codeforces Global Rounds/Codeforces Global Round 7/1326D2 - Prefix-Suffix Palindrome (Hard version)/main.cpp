#include <bits/stdc++.h>

using namespace std;
#define SIZE(s) ((int)s.size())

void failureFunction(vector<int> &LPS, string str)
{
    for(int i=0, j=1 ; j<SIZE(str) ; j++)
    {
        while(i>0 && str[i]!=str[j])
            i=LPS[i-1];

        i+=(str[i]==str[j]);
        LPS[j]=i;
    }
}

int longestPrefixPalindrome(string str)
{
    vector<int> LPS(SIZE(str)*2+1); // Longest proper prefix which is also suffix

    failureFunction(LPS, (str+"?"+string(str.rbegin(), str.rend())));

    return LPS[SIZE(str)*2];
}

string solve(string str)
{
    int start=0;

    // remove prefix == revese suffix (abcdfdcecda = dfdce)
    for(int l=0, r=SIZE(str)-1 ; l<r ; l++, r--)
        if(str[l]==str[r])
            start++;
        else
            break;

    string remainingStr=str.substr(start, SIZE(str)-2*start);
    string resultStr=str.substr(0, start);

    int prefix=longestPrefixPalindrome(remainingStr);
    int suffix=longestPrefixPalindrome(string(remainingStr.rbegin(), remainingStr.rend()));

    prefix > suffix ? resultStr+=remainingStr.substr(0, prefix)
                    : resultStr+=remainingStr.substr(SIZE(remainingStr)-suffix, suffix);

    return (resultStr+=str.substr(SIZE(str)-start, start));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin>>T;

    while(T--)
    {
        string str;
        cin>>str;

        cout<<solve(str)<<"\n";
    }

    return 0;
}

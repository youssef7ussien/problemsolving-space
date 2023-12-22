/**
 * Title: "Mirrored String II", Codeforces problem. 
 * Date: Monday, 22 August 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


string getPalindrome(const string &str, int left, int right) {
    map<char, bool> flags = {{'A', 1}, {'H', 1}, {'I', 1}, {'M', 1}, {'O', 1}, 
                                {'T', 1}, {'U', 1}, {'V', 1}, {'W', 1}, {'X', 1}, {'Y', 1}};

    while(left >= 0 && right < LEN(str)) {
        if(str[left] != str[right] || !flags[str[left]])
            break;
        left--, right++;
    }

    return str.substr(left + 1, max(right - left - 1, 0));
}

int solve(string str)
{
    int result = 0;
    for(int i = 0 ; i < LEN(str) ; i++) {
        // for odd substring
        result = max(result, LEN(getPalindrome(str, i, i)));

        // for even substring
        result = max(result, LEN(getPalindrome(str, i, i + 1)));
    }
    
    return result;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;

        cout<<solve(str)<<"\n";
    }
    
    return 0;
}
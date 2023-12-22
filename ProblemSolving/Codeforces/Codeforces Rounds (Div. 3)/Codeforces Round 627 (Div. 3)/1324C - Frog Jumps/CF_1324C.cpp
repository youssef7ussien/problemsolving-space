/**
 * Title: "Frog Jumps", Codeforces problem. 
 * Date: Wednesday, 29 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string str;
        cin>>str;

        str = 'R' + str + 'R';
        int result = 0;
        for(int i = 1, j = 0 ; i < LEN(str) ; i++)
            if(str[i] == 'R')
                result = max(result, i - j), j = i;

        cout<<result<<"\n";
    }
    
    return 0;
}

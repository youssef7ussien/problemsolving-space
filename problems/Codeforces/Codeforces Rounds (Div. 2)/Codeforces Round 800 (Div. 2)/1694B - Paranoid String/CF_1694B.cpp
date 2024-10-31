/**
 * Title: "Paranoid String", Codeforces problem. 
 * Date: Thursday, 16 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        string str;
        cin>>N>>str;

        if(LEN(str) <= 1)
            { cout<<LEN(str)<<"\n"; continue; }
        
        Long counter = LEN(str);
        for(int i = 1 ; i < LEN(str) ; i++)
            if(str[i] != str[i - 1])
                counter += i;

        cout<<counter<<"\n";
    }
    
    return 0;
}
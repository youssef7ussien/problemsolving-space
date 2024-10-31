/**
 * Title: "Palindromic Indices", Codeforces problem. 
 * Date: Sunday, 22 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        string str;
        cin>>N>>str;

        Long counter = 0;
        for(int i = LEN(str) / 2 ; i < N ; i++)
            if(str[LEN(str) / 2] == str[i])
                counter++;
            else
                break;

        for(int i = LEN(str) / 2 - 1 ; i >= 0 ; i--)
            if(str[LEN(str) / 2] == str[i])
                counter++;
            else
                break;
        
        cout<<counter<<"\n";
    }
    
    return 0;
}
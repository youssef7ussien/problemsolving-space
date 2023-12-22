/**
 * Title: "Infinite Replacement", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9
typedef long long               Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string s, t;
        cin>>s>>t;

        if(t.find('a') != string::npos)
            cout<<(SIZE(t) == 1 ? 1 : -1)<<"\n";
        else
            cout<<(Long)pow(2l, SIZE(s))<<"\n";
    }
    
    return 0;
}
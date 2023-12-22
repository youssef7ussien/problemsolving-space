/**
 * Title: "Fall Down", Codeforces problem. 
 * Date: Thursday, 21 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, M;
        cin>>N>>M;

        vector<string> str(N);
        for(auto &it : str)
            cin>>it;

        for(int k = 0 ; k < N ; k++)
            for(int i = 0 ; i < N - 1 ; i++)
                for(int j = 0 ; j < M ; j++) {
                    if(str[i][j] == '*' && str[i + 1][j] == '.')
                        str[i][j] = '.', str[i + 1][j] = '*';
                }
        
        for(auto &it : str)
            cout<<it<<"\n";
    }
    
    return 0;
}
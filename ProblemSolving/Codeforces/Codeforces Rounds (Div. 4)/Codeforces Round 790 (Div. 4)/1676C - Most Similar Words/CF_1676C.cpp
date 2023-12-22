/**
 * Title: "Most Similar Words", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<Long>            VL;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, M;
        cin>>N>>M;
        
        vector<string> strs(N);
        for(auto &it : strs)
            cin>>it;
        
        int minDiff = INF;
        for(int i = 0 ; i < N - 1 ; i++) {
            for(int k = i + 1 ; k < N ; k++) {
                int temp = 0;
                for(int j = 0 ; j < M ; j++)
                    temp += abs(((strs[i][j]) - 'a') - (strs[k][j] - 'a'));
                
                minDiff = min(temp, minDiff);
            }
        }

        cout<<minDiff<<"\n";
    }
    
    return 0;
}
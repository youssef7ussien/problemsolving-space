/**
 * Title: "Maximum Crossings (Easy Version)", Codeforces problem. 
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
typedef vector<PII>             VII;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VII ranges(N);
        for(int i = 1 ; i <= N ; i++) {
           CIN(num);
            ranges[i -  1] = {i, num};
        }

        int counter = 0;
        for(int i = 0 ; i < N ; i++)
            for(int j = i + 1 ; j < N ; j++)
                counter += (ranges[i].second >= ranges[j].second);

        cout<<counter<<"\n";
    }
    
    return 0;
}
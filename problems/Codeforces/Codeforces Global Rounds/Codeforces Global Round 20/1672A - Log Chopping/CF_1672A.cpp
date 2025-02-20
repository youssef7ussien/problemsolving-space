/**
 * Title: "Log Chopping", Codeforces problem. 
 * Date: Saturday, 23 April 2022 
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
        int N;
        cin>>N;
        
        int counter = 0;
        for(int i = 0 ; i < N ; i++) {
            CIN(temp);
            counter += temp - 1;
        }

        cout<<(counter % 2 == 0 ? "maomao90" : "errorgorn")<<"\n";

    }
    
    return 0;
}
/**
 * Title: "Playoff", Codeforces problem. 
 * Date: Thursday, 10 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;


int main()
{
    FAST_IO;
    TEST_CASES(T) {
        Long N;
        cin>>N;

        cout<<(Long)pow(2, N) - 1<<"\n";
    }
    return 0;
}
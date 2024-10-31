/**
 * Title: "Maximum Subarray Sum II", CSES problem. 
 * Date: Wednesday, 23 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)               freopen(file, "r", stdin)
#define FILE_OUT(file)              freopen(file, "w", stdout)
#define INF                         1e9+5

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;


int main()
{
    // TODO: Not implemented yet.
    
    #ifdef __DEBUG
        FILE_IN("samples\\__CSES_1644.in");
        FILE_OUT("samples\\__CSES_1644.out");
    #endif
    
    FAST_IO;
    
    int N, A, B;
    cin>>N>>A>>B;

    VI numbers(N), prefix(N + 1);
    for(int i = 1 ; i <= N ; i++) {
        cin>>numbers[i - 1];
        prefix[i] += prefix[i - 1] + numbers[i - 1];
    }

    int result = prefix[A], left = 0, right = B;
    for(int i = A - 1 ; i < N ; i++) {

    }
    

    return 0;
}
/**
 * Title: "Lunch Rush", Codeforces problem. 
 * Date: Sunday, 22 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9 + 5)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;

    int result = -INF;
    for(int i = 0 ; i < N ; i++) {
        int F, T;
        cin>>F>>T;

        result = max(result, (T > K ? F - (T - K) : F));
    }
    
    cout<<result<<"\n";
    return 0;
}
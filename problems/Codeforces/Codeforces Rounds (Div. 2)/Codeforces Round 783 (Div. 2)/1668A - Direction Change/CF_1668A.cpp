/**
 * Title: "Direction Change", Codeforces problem. 
 * Date: Tuesday, 19 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9
typedef long long               Long;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        Long N, M;
        cin>>N>>M;
        
        if(N > M)
            swap(N, M);

        if(N == 1)
            cout<<(M == 1 ? 0 : (M == 2 ? 1 : -1))<<"\n";
        else {
            N--, M--;
            cout<<(N + M + (M - N) - 1 * (M % 2 !=  N % 2))<<"\n";
        }
    }
    
    return 0;
}
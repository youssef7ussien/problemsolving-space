/**
 * Title: "Patchouli_s Magical Talisman", Codeforces problem. 
 * Date: Monday, 06 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9 + 5)

typedef long long               Long;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        int even = 0, minZeros = INF;
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            even += !(num & 1);
            minZeros = min(minZeros, __builtin_ctz(num));
        }

        cout<<even + minZeros - (even == N)<<"\n";
    }
    
    return 0;
}
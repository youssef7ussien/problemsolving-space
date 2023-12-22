/**
 * Title: "Print a Pedestal (Codeforces logo)", Codeforces problem. 
 * Date: Tuesday, 07 June 2022 
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
        int N;
        cin>>N;

        cout<<(N / 3 + (N % 3 == 2))<<" "<<(N / 3 + 1 + (N % 3 != 0))<<" "<<(N / 3 - 1)<<"\n";
    }
    
    return 0;
}
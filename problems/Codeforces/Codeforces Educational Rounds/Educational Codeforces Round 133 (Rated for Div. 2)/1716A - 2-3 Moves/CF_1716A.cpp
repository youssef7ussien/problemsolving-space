/**
 * Title: "2-3 Moves", Codeforces problem. 
 * Date: Thursday, 04 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        cout<<(N == 1 ? 2 : N / 3 + (N % 3 != 0))<<"\n";
    }
    
    return 0;
}
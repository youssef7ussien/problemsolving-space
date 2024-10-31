/**
 * Title: "Frog Jumping", Codeforces problem. 
 * Date: Wednesday, 30 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        Long a, b, k;
        cin>>a>>b>>k;

        cout<<a * (k / 2 + k % 2) - b * (k / 2)<<"\n";
    }
    
    return 0;
}
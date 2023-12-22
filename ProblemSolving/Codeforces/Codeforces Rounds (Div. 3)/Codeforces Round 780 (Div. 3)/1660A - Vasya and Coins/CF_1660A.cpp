/**
 * Title: "Vasya and Coins", Codeforces problem. 
 * Date: Thursday, 31 March 2022 
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
        Long a, b;
        cin>>a>>b;

        cout<<(a == 0 ? 1 : a + b * 2 + 1)<<"\n";
    }
    
    return 0;
}
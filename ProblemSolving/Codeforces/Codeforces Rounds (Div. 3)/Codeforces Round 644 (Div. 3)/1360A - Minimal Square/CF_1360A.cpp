/**
 * Title: "Minimal Square", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
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
        int a, b;
        cin>>a>>b;

        cout<<(pow(max(a, max(b, min(a, b) * 2)), 2))<<"\n";
    }
    
    return 0;
}
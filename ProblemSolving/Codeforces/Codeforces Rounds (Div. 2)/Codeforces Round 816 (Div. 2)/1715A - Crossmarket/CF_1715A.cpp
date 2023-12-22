/**
 * Title: "Crossmarket", Codeforces problem. 
 * Date: Saturday, 20 August 2022 
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
        int n, m;
        cin>>n>>m;
        
        if(n == 1 && m == 1)
            cout<<"0\n";
        else {
            if(n > m) swap(n, m);

            cout<<(n * 2 + m - 2)<<"\n";
        }
    }
    
    return 0;
}
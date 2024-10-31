/**
 * Title: "Mathematical Circus", Codeforces problem. 
 * Date: Wednesday, 17 August 2022 
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
        int n, k;
        cin>>n>>k;

        if(k % 4 == 0)
            { cout<<"NO\n"; continue; }

        cout<<"YES\n";
        if(k % 2 == 0) {
            for(int i = 1, j = 0 ; i <= n ; i += 2, j++)
                if(j % 2 == 0)
                    cout<<i + 1<<" "<<i<<"\n";
                else 
                    cout<<i<<" "<<i + 1<<"\n";
        }
        else
            for(int i = 1 ; i <= n ; i += 2)
                cout<<i<<" "<<i + 1<<"\n";
    }
    
    return 0;
}
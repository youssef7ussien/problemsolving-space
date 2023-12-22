/**
 * Title: "Same Parity Summands", Codeforces problem. 
 * Date: Wednesday, 20 April 2022 
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
        int N, K;
        cin>>N>>K;

        if(N - (K - 1) > 0 && (N - (K - 1)) % 2 != 0) {
            cout<<"YES\n";
            for(int i = 0 ; i < K - 1 ; i++)
                cout<<"1"<<" ";
            cout<<N - (K - 1)<<"\n";
        }
        else if(N - 2 * (K - 1) > 0 && (N - 2 * (K - 1)) % 2 == 0)  {
            cout<<"YES\n";
            for(int i = 0 ; i < K - 1 ; i++)
                cout<<"2"<<" ";
            cout<<N - 2 * (K - 1)<<"\n";
        }
        else
            cout<<"NO\n";
    }
    
    return 0;
}
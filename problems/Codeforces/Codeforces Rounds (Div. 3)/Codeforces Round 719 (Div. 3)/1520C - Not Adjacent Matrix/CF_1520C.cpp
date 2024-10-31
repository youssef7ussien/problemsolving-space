/**
 * Title: "Not Adjacent Matrix", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        if(N == 2)
            cout<<"-1\n";
        else {
            int count = 0;
            for(int i = 1 ; i <= N * N ; i += 2) {
                cout<<i<<" ";
                if(++count == N)
                    cout<<"\n", count = 0;
            }

            for(int i = 2 ; i <= N * N ; i += 2) {
                cout<<i<<" ";
                if(++count == N)
                    cout<<"\n", count = 0;
            }
        }
    }
    
    return 0;
}
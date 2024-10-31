/**
 * Title: "Wonderful Permutation", Codeforces problem. 
 * Date: Saturday, 13 August 2022 
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

        int counter = 0;        
        for(int i = 0 ; i < N ; i++) {
            int num; cin>>num;

            counter += (i < K && num > K);
        }

        cout<<counter<<"\n";
    }
    
    return 0;
}
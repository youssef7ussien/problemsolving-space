/**
 * Title: "Rising Sand", Codeforces problem. 
 * Date: Tuesday, 28 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, K;
        cin>>N>>K;
        
        VI arr(N);
        for(auto &it : arr)
            cin>>it;
        
        if(K == 1)
            { cout<<((N + 1) / 2  - 1)<<"\n"; continue; }
        
        int counter = 0;
        for(int i = 1 ; i < N - 1 ; i++)
            counter += (arr[i] > arr[i - 1] + arr[i + 1]);

        cout<<counter<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Maximal Continuous Rest", Codeforces problem. 
 * Date: Thursday, 12 May 2022 
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
    
    int N;
    cin>>N;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;

    int result = 0;
    for(int i = 0, j = 0; i < 2 * N ; i++) {
        if(arr[i % N] == 1)
            result = max(result, ++j);
        else
            j = 0;
    }

    cout<<result<<"\n";
    return 0;
}
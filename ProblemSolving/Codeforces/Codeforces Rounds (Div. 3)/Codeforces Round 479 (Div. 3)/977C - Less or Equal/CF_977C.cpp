/**
 * Title: "Less or Equal", Codeforces problem. 
 * Date: Monday, 15 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;

    sort(ALL(arr));

    cout<<(K == 0 ? (arr[0] == 1 ? -1 : 1) : (arr[K - 1] == arr[K] ? -1 : arr[K - 1]))<<"\n";
    return 0;
}
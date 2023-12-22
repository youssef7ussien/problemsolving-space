/**
 * Title: "Also Try Minecraft", Codeforces problem. 
 * Date: Thursday, 04 August 2022 
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
    
    int N, M;
    cin>>N>>M;
    
    VI arr(N + 1);
    vector<Long> prefix(N + 2), suffix(N + 2);
    for(int i = 1 ; i <= N ; i++) {
        cin>>arr[i];
        prefix[i] = prefix[i - 1] + (i == 1 ? 0 : max(0, arr[i - 1] - arr[i]));
    }
    
    for(int i = N ; i >= 1 ; i--)
        suffix[i] = suffix[i + 1] + (i == N ? 0 : max(0, arr[i + 1] - arr[i]));

    while(M--) {
        int S, T;
        cin>>S>>T;

        cout<<(T > S ? prefix[T] - prefix[S] : suffix[T] - suffix[S])<<"\n";
    }

    return 0;
}
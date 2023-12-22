#include <bits/stdc++.h>

using namespace std;
#define MAX 2e5+5

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> temperatures(MAX, 0), rangeSum(MAX, 0);
    int N, K, Q;
    cin>>N>>K>>Q;

    for(int i=0 ; i<N ; i++) {
        int l, r; cin>>l>>r;
        temperatures[l]++, temperatures[r+1]--;
    }

    for(int i=1 ; i<MAX ; i++)
        temperatures[i]+=temperatures[i-1], rangeSum[i]=rangeSum[i-1]+(temperatures[i]>=K);

    while(Q--) {
        int a, b; cin>>a>>b;
        cout<<(rangeSum[b]-rangeSum[a-1])<<"\n";
    }

    return 0;
}

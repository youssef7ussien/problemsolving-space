/**
 * Author: Youssef Hussien
 * Title: "Static Range Sum Queries", CSES problem. 
 * Date: Monday, 14 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<long long>           VL;

int main()
{
    FAST_IO;
    
    int N, Q;
    cin>>N>>Q;

    VL prefix(N + 1);
    for(int i = 1 ; i <= N ; i++) {
        int num; cin>>num;
        prefix[i] += num + prefix[i - 1];
    }

    while(Q--) {
        int l, r;
        cin>>l>>r;

        cout<<prefix[r] - prefix[l - 1]<<"\n";
    }

    return 0;
}
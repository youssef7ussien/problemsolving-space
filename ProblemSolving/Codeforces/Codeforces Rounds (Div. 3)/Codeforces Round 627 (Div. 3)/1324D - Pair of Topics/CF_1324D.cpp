/**
 * Title: "Pair of Topics", Codeforces problem. 
 * Date: Thursday, 30 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define CIN(T)                  int T; cin>>T;
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

    for(auto &it : arr) {
        CIN(num);
        it -= num;
    }
    
    sort(ALL(arr));

    Long counter = 0;
    for(int i = 0 ; i < N - 1 ; i++) {
        int index = lower_bound(ALL(arr), -arr[i] + 1) - arr.begin();
        counter += N - (index > i ? index : i + 1);
    }

    cout<<counter<<"\n";
    return 0;
}
/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
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
    cin>>N;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;

    sort(ALL(arr));

    cin>>K;
    while(K--) {
        int l, r;
        cin>>l>>r;

        auto second = upper_bound(ALL(arr), r) - arr.begin();
        if(second == 0)
            { cout<<"0\n"; continue; }

        cout<<second - (lower_bound(ALL(arr), l) - arr.begin())<<" ";
    }
    
    return 0;
}
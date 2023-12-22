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
    cin>>N>>K;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;

    while(K--) {
        int num;
        cin>>num;

        cout<<(binary_search(ALL(arr), num) ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}
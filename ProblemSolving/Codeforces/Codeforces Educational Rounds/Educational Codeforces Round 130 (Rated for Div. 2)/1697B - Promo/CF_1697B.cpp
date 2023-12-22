/**
 * Title: "Promo", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N, Q;
    cin>>N>>Q;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;

    sort(R_ALL(arr));
    
    vector<Long> prefix(N + 1);
    for(int i = 1 ; i <= N ; i++)
        prefix[i] = arr[i - 1] + prefix[i - 1];

    while(Q--) {
        int X, Y;
        cin>>X>>Y;
        
        cout<<prefix[X] - prefix[X - Y]<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Little Girl and Maximum Sum", Codeforces problem. 
 * Date: Wednesday, 18 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N, Q;
    cin>>N>>Q;
    
    VI arr(N), range(N + 2);
    for(auto &it : arr)
        cin>>it;

    while(Q--) {
        int left, right;
        cin>>left>>right;
        range[left]++, range[right + 1]--;
    }

    for(int i = 1 ; i < LEN(range) ; i++)
        range[i] += range[i - 1];

    sort(ALL(arr));
    sort(ALL(range));

    Long counter = 0;
    for(int i = 0 ; i < LEN(arr) ; i++)
        counter += 1LL * arr[i] * range[i + 2];
        
    cout<<counter<<"\n";
    return 0;
}
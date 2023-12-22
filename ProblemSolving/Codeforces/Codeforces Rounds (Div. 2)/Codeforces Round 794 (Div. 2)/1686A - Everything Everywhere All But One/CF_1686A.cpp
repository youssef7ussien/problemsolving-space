/**
 * Title: "Everything Everywhere All But One", Codeforces problem. 
 * Date: Wednesday, 25 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI arr(N);
        int sum = 0;
        for(auto &it : arr) {
            cin>>it;
            sum += it;
        }
        
        bool can = false;
        for(int i = 0 ; i < N ; i++) {
            if((sum - arr[i]) % (N - 1) == 0 && (sum - arr[i]) / (N - 1) == arr[i])
                { can = true; break; }
        }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}
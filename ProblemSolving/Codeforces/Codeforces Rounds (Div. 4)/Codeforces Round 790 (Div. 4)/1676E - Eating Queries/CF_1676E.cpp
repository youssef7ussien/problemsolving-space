/**
 * Title: "Eating Queries", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<Long>            VL;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, Q;
        cin>>N>>Q;
        
        VI arr(N);
        for(auto &it : arr)
            cin>>it;

        sort(ALL(arr));

        VI suffix(N);
        for(int i = N - 1 ; i >= 0 ; i--)
            suffix[i] += arr[i] + (i == N - 1 ? 0 : suffix[i + 1]);

        while(Q--) {
            CIN(num);

            if(num > suffix[0])
                { cout<<"-1\n"; continue; }
            
            auto index = lower_bound(ALL(suffix), num, std::greater<int>());
            if(index == suffix.end())
                cout<<1<<"\n";
            else 
                cout<<N - (index - suffix.begin()) + (suffix[index - suffix.begin()] != num)<<"\n";

        }
    }
    
    return 0;
}
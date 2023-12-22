/**
 * Title: "Stone Age Problem", Codeforces problem. 
 * Date: Saturday, 14 May 2022 
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
    
    int N, Q;
    cin>>N>>Q;
    
    VI arr(N), check(N);
    Long prefix = 0;
    for(auto &it : arr) {
        cin>>it;
        prefix += it;
    }

    pair<int, Long> equal = {0, 0};
    while(Q--) {
        int type;
        cin>>type;

        if(type == 1) {
            int pos, num;
            cin>>pos>>num;
            if(equal.FF != 0 && check[pos - 1] < equal.FF)
                arr[pos - 1] = equal.SS, check[pos - 1] = equal.FF;
                
            prefix = prefix - arr[pos - 1] + num;
            cout<<prefix<<"\n";
            
            arr[pos - 1] = num;
        }
        else {
            int num;
            cin>>num;

            equal = {equal.FF + 1, num};
            prefix = 1LL * equal.SS * N;
            cout<<prefix<<"\n";
        }

    }
    
    return 0;
}
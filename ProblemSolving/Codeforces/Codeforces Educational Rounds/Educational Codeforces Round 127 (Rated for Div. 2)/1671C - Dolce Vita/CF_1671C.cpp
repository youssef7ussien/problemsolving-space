/**
 * Title: "Dolce Vita", Codeforces problem. 
 * Date: Friday, 22 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9)

typedef long long               Long;
typedef vector<int>             VI;
typedef vector<Long>            VL;


int upperBound(Long prefix, Long X, int index, int start)
{
    int left = start, right = INF;
 
    while(left < right) {
        int middle = left + (right - left) / 2;
        
        X >= prefix + (1ll  * middle * index) ? left = middle + 1 : right = middle;
    }
 
    return right;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N; Long X, prefix = 0;
        cin>>N>>X;

        VI prices(N);
        for(auto &it : prices) {
            cin>>it;
            prefix += it;
        }

        sort(ALL(prices));

        int lastDay = 0; Long counter = 0;
        for(int i = SIZE(prices) ; i > 0 ; i--) {
            if(prefix <= X) {
                int day = upperBound(prefix, X, i, lastDay);
                counter += 1ll * day * i - 1ll * lastDay * i;
                lastDay = day;
            }
            prefix -= prices[i - 1];
        }
        
        cout<<counter<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Game with Cards", Codeforces problem. 
 * Date: Monday, 23 May 2022 
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
        int N, M;
        cin>>N;
        
        VI arrA(N);
        for(auto &it : arrA)
            cin>>it;

        cin>>M;
        VI arrB(M);
        for(auto &it : arrB)
            cin>>it;
        
        sort(ALL(arrA));
        sort(ALL(arrB));

        cout<<(arrA.back() >= arrB.back() ? "Alice" : "Bob")<<"\n"
            <<(arrB.back() >= arrA.back() ? "Bob" : "Alice")<<"\n";
    }
    
    return 0;
}
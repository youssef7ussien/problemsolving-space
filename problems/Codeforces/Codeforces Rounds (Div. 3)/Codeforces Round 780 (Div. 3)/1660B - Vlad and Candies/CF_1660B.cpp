/**
 * Title: "Vlad and Candies", Codeforces problem. 
 * Date: Thursday, 31 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        VI freq(N);
        for(auto &it : freq)
            cin>>it;

        sort(ALL(freq));
     
        if(N == 1)
            cout<<(freq[0] > 1 ? "NO" : "YES")<<"\n";
        else
            cout<<(abs(freq[N - 1] - freq[N - 2]) > 1 ? "NO" : "YES")<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Black and White Stripe", Codeforces problem. 
 * Date: Saturday, 11 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, K;
        string str;
        cin>>N>>K>>str;

        VI prefix(N + 1);
        for(int i = 1 ; i <= LEN(str) ; i++)
            prefix[i] = (str[i - 1] == 'W') + (i == 0 ? 0 : prefix[i - 1]);
        
        int result = INF;
        for(int i = K ; i <= LEN(str) ; i++)
            result = min(result, prefix[i] - prefix[i - K]);

        cout<<result<<"\n";
    }
    
    return 0;
}
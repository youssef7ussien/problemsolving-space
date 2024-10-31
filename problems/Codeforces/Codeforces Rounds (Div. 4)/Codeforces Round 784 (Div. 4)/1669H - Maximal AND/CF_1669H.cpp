/**
 * Title: "Maximal AND", Codeforces problem. 
 * Date: Monday, 25 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, K;
        cin>>N>>K;
        VI freq(31);
        for(int i = 0 ; i < N ; i++) {
            CIN(temp);
            for(int j = 30 ; j >= 0 ; j--)
                    freq[j] += ((temp & (1 << j)) != 0);
        }

        int result = 0;
        for(int i = 30 ; i >= 0 ; i--)
            if(N - freq[i] <= K)
                K -= N - freq[i], result += (1 << i);
        
        cout<<result<<"\n";
    }
    
    return 0;
}
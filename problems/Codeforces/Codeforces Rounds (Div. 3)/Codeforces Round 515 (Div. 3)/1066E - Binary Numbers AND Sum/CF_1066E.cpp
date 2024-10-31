/**
 * Title: "Binary Numbers AND Sum", Codeforces problem. 
 * Date: Thursday, 30 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define MOD                     int(998244353)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N, M;
    string a, b;
    cin>>N>>M>>a>>b;
        
    reverse(ALL(a)), reverse(ALL(b));
    
    VI freq(max(N, M));
    for(int i = M - 1 ; i >= 0 ; i--)
        freq[i] = (b[i] == '1') + (i == M - 1 ? 0 : freq[i + 1]);

    Long result = 0, power = 1;
    for(int i = 0 ; i < N ; i++) {
        if(a[i] == '1')
            result = (result + power * freq[i]) % MOD;
        power = (power * 2) % MOD;
    }
    
    cout<<result<<"\n";
    return 0;
}
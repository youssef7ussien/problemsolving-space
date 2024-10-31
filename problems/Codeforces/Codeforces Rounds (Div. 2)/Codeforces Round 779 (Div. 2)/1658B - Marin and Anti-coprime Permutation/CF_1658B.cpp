/**
 * Title: "Marin and Anti-coprime Permutation", Codeforces problem. 
 * Date: Sunday, 27 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9
typedef long long                   Long;
#define MOD                         Long(998244353)


Long fact(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
        result = (result % MOD * i % MOD) % MOD;
 
    return result;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        Long N;
        cin>>N;

        if(N % 2 != 0) {
            cout<<0<<"\n";
            continue;
        }
        Long num = fact(N / 2);
        cout<<(num * num) % MOD<<"\n";
    }

    return 0;
}
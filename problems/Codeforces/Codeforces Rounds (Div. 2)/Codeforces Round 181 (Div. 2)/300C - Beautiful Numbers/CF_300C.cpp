/**
 * Title: "Beautiful Numbers", Codeforces problem. 
 * Date: Sunday, 13 March 2022 
 *
 * 
 * hint: https://www.youtube.com/watch?v=D8y3lYSHObY
 *
 *      - When calculate nCr need to (Modular Multiplicative Inverse)
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         (int)(1e6+5)
#define MOD                         (int)(1e9+7)

typedef long long                   Long;
typedef vector<Long>                VL;


VL initFact() 
{
    VL fact(INF);
    
    fact[0] = 1;
    for(int i = 1 ; i < INF ; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    return fact;  
}

bool check(int sum, int A, int B) 
{
    while(sum) {
        int temp = sum % 10;
        if(temp != A && temp != B)
            return false;
        sum /= 10;
    }
    
    return true;
}

Long power(Long a, int p)
{
    Long result = 1;
    a %= MOD;
    while(p > 0) {
        if(p & 1)
            result = (result * a) % MOD;
        p >>= 1;
        a = (a * a) % MOD;
    }

    return result;
}

Long nCr(const VL &fact, int n, int r)
{
    // power(fact[n - r] * fact[r], MOD - 2) ==> this is Modular Multiplicative Inverse
    return (fact[n] * power(fact[n - r] * fact[r], MOD - 2)) % MOD;
}


int main()
{
    FAST_IO;
    
    VL fact = initFact();

    int A, B, N;
    cin>>A>>B>>N;

    Long result = 0;
    for(int i = 0 ; i <= N ; i++)
        if(check(A * i + B * (N - i), A, B))
            result = (result + nCr(fact, N, i)) % MOD;

    cout<<result<<"\n";
    return 0;
}
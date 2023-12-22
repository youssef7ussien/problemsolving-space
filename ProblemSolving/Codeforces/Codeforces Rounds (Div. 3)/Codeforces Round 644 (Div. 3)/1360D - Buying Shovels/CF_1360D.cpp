/**
 * Title: "Buying Shovels", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9+2)


int solve(int n, int k) // calc max divisor
{
    int result = n;
    for(int i = 1 ; i <= n / i ; i++)
        if(n % i == 0) {
            if(i <= k)
            result = min(result, n / i);
            if(n / i <= k)
                result = min(result, i);
        }

    return result;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int n, k;
        cin>>n>>k;

        if(k >= n)
            cout<<1<<"\n";
        else
            cout<<solve(n, k)<<"\n";
    }
    
    return 0;
}
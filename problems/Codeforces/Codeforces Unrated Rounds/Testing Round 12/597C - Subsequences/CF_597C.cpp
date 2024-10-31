/**
 * Title: "Subsequences", Codeforces problem. 
 * Date: Monday, 22 August 2022 
 * hint: https://stackoverflow.com/a/15058391/13377098
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

int solve1(const VI &arr, int k) // Complextiy: N^2 * K
{
    vector<VI> dp(LEN(arr), VI(k));
    
    for(int i = 0 ; i < LEN(arr) ; i++)
        dp[i][0] = 1;

    for(int i = 0 ; i < LEN(arr) ; i++) {
        for(int j = 0 ; j < i ; j++) 
            if(arr[i] > arr[j])
                for(int p = 1 ; p < k ; p++)
                    dp[i][p] += dp[j][p - 1];
    }

    for(int i = 0 ; i < LEN(arr) ; i++) {
        cout<<setw(4)<<arr[i]<<" | ";
        for(auto &it : dp[i])
            cout<<setw(3)<<it<<" ";
        cout<<"\n";
    }

    int counter = 0;
    for(int i = 0 ; i < LEN(arr) ; i++)
        counter += dp[i][k - 1];
    
    return counter;
}

int solve2(const VI &arr, int k) // Complextiy: N * K * S
{
    vector<VI> dp(LEN(arr), VI(k));
    
    for(int i = 0 ; i < LEN(arr) ; i++)
        dp[i][0] = 1;

    for(int p = 1 ; p < k ; p++) {

        VI num(1e5);

        for(int i = 1 ; i < LEN(arr) ; i++) {
            num[arr[i - 1]] = dp[i - 1][p - 1];

            for(int j = 0 ; j < arr[i] ; j++)
                dp[i][p] += num[j];
        }
        if(p == k - 1) {
            for(int i = 1 ; i <= 20 ; i++)
                cout<<setw(3)<<i<<" ";
            cout<<"\n";
            for(int i = 0 ; i < 20 ; i++)
                cout<<setw(3)<<num[i]<<" ";
            cout<<"\n";
        }
    }
    

    for(int i = 0 ; i < LEN(arr) ; i++) {
        cout<<setw(4)<<arr[i]<<" | ";
        for(auto &it : dp[i])
            cout<<setw(3)<<it<<" ";
        cout<<"\n";
    }

    int counter = 0;
    for(int i = 0 ; i < LEN(arr) ; i++)
        counter += dp[i][k - 1];
    
    return counter;
}

int main()
{
    FAST_IO;
    
    // TODO: Not implemented yet.
    // https://codeforces.com/contest/597/submission/14201214
    
    int N, K;
    cin>>N>>K;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;
    
    cout<<solve2(arr, K + 1)<<"\n";
    return 0;
}
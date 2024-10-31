/**
 * Title: "Playlist", Codeforces problem. 
 * Date: Monday, 08 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;
    
    VII arr(N);
    for(auto &it : arr)
        cin>>it.SS>>it.FF;
    
    sort(ALL(arr), greater<PII>());

    Long result = 0, sum = 0;
    priority_queue<int, vector<int>, greater<int>> current;

    for(auto &it : arr) {
        current.push(it.SS);
        sum += it.SS;
        while(LEN(current) > K)
            sum -= current.top(), current.pop();
        
        result = max(result, sum * it.FF);
    }
    
    cout<<result<<"\n";
    return 0;
}
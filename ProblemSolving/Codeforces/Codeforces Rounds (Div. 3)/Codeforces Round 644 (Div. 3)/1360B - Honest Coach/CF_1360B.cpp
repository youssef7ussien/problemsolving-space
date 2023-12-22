/**
 * Title: "Honest Coach", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI arr(N);
        for(auto &it : arr)
            cin>>it;
        
        sort(ALL(arr));

        int minDiff = INF;
        for(int i = 0 ; i < N - 1 ; i++)
            minDiff = min(minDiff, arr[i + 1] - arr[i]);

        cout<<minDiff<<"\n";
    }
    
    return 0;
}
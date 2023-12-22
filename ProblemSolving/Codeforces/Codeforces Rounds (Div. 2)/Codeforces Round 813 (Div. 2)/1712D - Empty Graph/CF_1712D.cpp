/**
 * Title: "Empty Graph", Codeforces problem. 
 * Date: Sunday, 14 August 2022 4
 * Video to solve problem (by Competitive Coding - Newton School): https://www.youtube.com/watch?v=FuiCKgDLBCY
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9
typedef vector<int>             VI;


bool check(VI arr, int K, int middle) 
{
    for(auto &it : arr)
        if(2 * it < middle) {
            it = INF;
            if(--K < 0)
                return false;
        }

    if(K >= 1)
        return (K > 1 ? true : *max_element(ALL(arr)) >= middle);
    
    for(int i = 1 ; i < LEN(arr) ; i++)
        if(min(arr[i], arr[i - 1]) >= middle)
            return true;
    
    return false;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, K;
        cin>>N>>K;
        
        VI arr(N);
        for(auto &it : arr)
            cin>>it;
        
        int left = 1, right = INF;
        while(left < right) {
            int middle = left + (right - left + 1) / 2;
            check(arr, K, middle) ? left = middle : right = middle - 1;
        }

        cout<<left<<"\n";
    }
    
    return 0;
}
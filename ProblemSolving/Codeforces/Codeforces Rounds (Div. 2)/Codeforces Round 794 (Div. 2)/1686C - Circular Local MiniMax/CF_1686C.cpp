/**
 * Title: "Circular Local MiniMax", Codeforces problem. 
 * Date: Sunday, 29 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI arr(N), result(N);
        for(auto &it : arr)
            cin>>it;
        
        sort(ALL(arr));
        for(int i = 0, j = 0 ; i < N / 2 ; i++, j += 2)
            result[j] = arr[i], result[j + 1] = arr[i + N / 2];
        
        bool can = true;
        for(int i = 0 ; i < N ; i++)
            if(!(result[((i - 1) % N + N) % N] < result[i] && result[i] > result[(i + 1) % N]) 
            && !(result[((i - 1) % N + N) % N] > result[i] && result[i] < result[(i + 1) % N]))
                { can = false; break; }

        if(!can)
            cout<<"NO\n";
        else {
            cout<<"YES\n";
            for(auto &it : result)
              cout<<it<<" ";
            cout<<"\n";
        }
    }
    
    return 0;
}
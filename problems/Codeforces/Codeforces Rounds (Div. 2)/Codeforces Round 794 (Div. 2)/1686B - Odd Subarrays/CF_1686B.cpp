/**
 * Title: "Odd Subarrays", Codeforces problem. 
 * Date: Wednesday, 25 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

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
        
        VI arr(N);
        for(auto &it : arr)
            cin>>it;
        
        int counter = 0;
        for(int i = 0 ; i < N - 1 ; i++)
            if(arr[i] > arr[i + 1])
                counter++, i++;

        cout<<counter<<"\n";
    }
    
    return 0;
}
/**
 * Title: "2_Sort", Codeforces problem. 
 * Date: Friday, 17 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, K;
        cin>>N>>K;
        
        VI arr(N);
        for(auto &it : arr)
            cin>>it;
        
        K++;
        int left = 0, right = 1, counter = 0;
        while(right < N) {
            if(right <= left)
                right = left + 1;

            while(right < N && right - left < K && arr[right] * 2 > arr[right - 1])
                right++;
            
            if(right - left == K)
                counter++;
            
            left++;
        }

        cout<<counter<<"\n";
    }
    
    return 0;
}
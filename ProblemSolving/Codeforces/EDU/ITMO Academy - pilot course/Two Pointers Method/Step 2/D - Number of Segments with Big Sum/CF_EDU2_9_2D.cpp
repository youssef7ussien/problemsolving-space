/**
 * Title: "Number of Segments with Big Sum", Uncategorized problem. 
 * Date: Sunday, 24 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    int N;
    Long S;
    cin>>N>>S;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;
    
    int left = 0, right = 0;
    Long sum = 0, result = 0;
    while(right < N) {
        sum += arr[right];
        
        if(sum >= S)
            result += (N - 1) - right + 1;

        while(left <= right && sum >= S) {
            sum -= arr[left++];
            
            if(sum >= S)
                result += (N - 1) - right + 1;
        }
        
        right++;
    }
    
    cout<<result<<"\n";
    return 0;
}
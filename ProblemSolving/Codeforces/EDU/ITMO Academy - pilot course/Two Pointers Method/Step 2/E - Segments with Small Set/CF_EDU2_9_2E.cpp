/**
 * Title: "Segments with Small Set", Uncategorized problem. 
 * Date: Sunday, 24 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define LEN(v)                  ((int)((v).size()))
typedef long long               Long;
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;
    
    map<int, int> freq;
    int left = 0, right = 0;
    Long result = 0;
    
    while(right < N) {
        freq[arr[right]]++;
        
        while(left <= right && LEN(freq) > K) {
            if(--freq[arr[left]] == 0)
                freq.erase(arr[left]);
            left++;    
        }

        result += right - left + 1;
        right++;
    }
    
    cout<<result<<"\n";
    return 0;
}
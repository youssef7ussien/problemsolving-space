/**
 * Title: "Segment with Small Sum", Uncategorized problem. 
 * Date: Sunday, 24 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<int>             VI;


Long withTwoPointer(const VI &arr, int S) 
{
    int N = arr.size(), left = 0, right = 0;
    Long sum = 0, result = 0;
    while(right < N) {
        sum += arr[right];
        
        while(left < right && sum > S)
            sum -= arr[left++];
        
        if(sum <= S)
            result = max(result, 1LL * right - left + 1);
        
        right++;
    }

    return result;
}

Long withPrefixSum(const VI &arr, int S) 
{
    int N = arr.size();
    
    vector<Long> prefix(N + 1);
    for(int i = 1; i <= N ; i++)
        prefix[i] = arr[i - 1] + prefix[i - 1];
        
    int left = 1, right = 1;
    Long result = 0;
    while(right <= N) {
        prefix[right] - prefix[left - 1] <= S ? right++ : left++;
        result = max(result, 1LL * right - left);
    }

    return result;
}

int main()
{
    FAST_IO;
    
    int N;
    Long S;
    cin>>N>>S;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;
    
    cout<<withPrefixSum(arr, S)<<"\n";
    // cout<<withTwoPointer(arr, S)<<"\n";
    return 0;
}
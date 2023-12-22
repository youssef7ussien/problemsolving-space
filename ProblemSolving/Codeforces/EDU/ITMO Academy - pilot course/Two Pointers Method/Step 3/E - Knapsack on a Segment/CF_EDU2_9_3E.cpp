/**
 * Title: "Knapsack on a Segment", Uncategorized problem. 
 * Date: Tuesday, 26 July 2022
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
    
    VI arr(N), cost(N);
    for(auto &it : arr)
        cin>>it;
    
    for(auto &it : cost)
        cin>>it;

    int left = 0, right = 0;
    Long sum = 0, sumCost = 0, result = 0;

    while(right < N) {
        sum += arr[right], sumCost += cost[right];
        
        while(left < right && sum > S)
            sum -= arr[left], sumCost -= cost[left++];
        
        if(sum <= S)
            result = max(result, sumCost);
        
        right++;
    }

    cout<<result<<"\n";
    return 0;
}
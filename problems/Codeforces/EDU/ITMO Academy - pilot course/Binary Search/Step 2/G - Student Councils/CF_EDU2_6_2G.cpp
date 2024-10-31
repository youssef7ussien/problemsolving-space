/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<int>             VI;


bool check(const VI &arr, int K, Long middle)
{
    Long total = K * middle;
    for(auto &it : arr) {
        total -= min(1LL * it, min(middle, total));
        
        if(total == 0)
            return true;
    }
    
    return total == 0;
}

Long binarySearch(const VI &arr, int K)
{
    Long left = 0, right = 1e13;
    while(left < right) {
        Long middle = left + (right - left + 1) / 2;

        check(arr, K, middle) ? left = middle : right = middle - 1;
    }

    return left;
}

int main()
{
    FAST_IO;
    
    int K, N;
    cin>>K>>N;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;
    
    cout<<binarySearch(arr, K)<<"\n";
    return 0;
}
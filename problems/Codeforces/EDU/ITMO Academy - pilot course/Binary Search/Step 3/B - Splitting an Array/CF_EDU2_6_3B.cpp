/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Wednesday, 06 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<int>             VI;


bool check(const VI &arr, int K, Long middle)
{   
    int counter = 1; Long sum = 0;
    for(int i = 0 ; i < LEN(arr) ; i++)
        if(sum + arr[i] <= middle)
            sum += arr[i];
        else 
            counter++, sum = arr[i];

    return counter <= K;
}

Long binarySearch(const VI &arr, int K)
{   
    Long left = 0, right = 0;
    for(auto &it : arr)
        left = max(left, 1LL * it), right += it;

    while(left < right) {
        Long middle = left + (right - left) / 2;
        check(arr, K, middle) ? right = middle : left = middle + 1;
    }
 
    return right;
}

int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;
        
    cout<<binarySearch(arr, K)<<"\n";
    return 0;
}
/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e10
typedef long long               Long;
typedef vector<pair<int, int>>  VII;


// the number of elements in the set that less than middle
Long countLess(const VII &arr, Long middle) {
    Long counter = 0;
    for(auto &it : arr)
        if(middle > it.FF)
            counter += min(1LL * it.SS, middle) - it.FF + (middle > it.SS);

    return counter;
}

Long binarySearch(const VII &arr, int K)
{
    Long left = -INF, right = INF;
    while(left + 1 < right) {
        Long middle = (right + left) / 2;
 
        countLess(arr, middle) <= Long(K) ? left = middle : right = middle;
    }
 
    return left;
}

int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;
    
    VII arr(N);
    for(auto &it : arr)
        cin>>it.FF>>it.SS;

    cout<<binarySearch(arr, K)<<"\n";
    return 0;
}
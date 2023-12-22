/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Wednesday, 06 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;

// the number of elements in the set that less than middle
Long countLess(Long N, Long middle) {
    Long counter = 0;
    middle--;
    for(int i = 1 ; i <= N ; i++)
        counter += min(middle / i, 1LL * N);

    return counter;
}

Long binarySearch(Long N, Long K)
{
    Long left = 1, right = N * N;
    while(left < right) {
        Long middle = left + (right - left + 1) / 2;
 
        countLess(N, middle) < K ? left = middle : right = middle - 1;
    }
 
    return left;
}

int main()
{
    FAST_IO;
    
    Long N, K;
    cin>>N>>K;

    cout<<binarySearch(N, K)<<"\n";
    return 0;
}
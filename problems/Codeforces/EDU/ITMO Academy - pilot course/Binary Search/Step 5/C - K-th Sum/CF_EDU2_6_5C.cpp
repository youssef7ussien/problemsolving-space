/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e13
typedef long long               Long;
typedef vector<int>             VI;


// the number of elements in the set that less than middle
Long countLess(const VI &arrA, const VI &arrB, Long middle) {
    Long counter = 0;
    for(auto &it : arrA) {
        if(1LL * it > middle)
            break;

        int index = lower_bound(ALL(arrB), middle - it) - arrB.begin();
        
        if(index == 0)
            break;

        counter += index;
    }

    return counter;
}

Long binarySearch(const VI &arrA, const VI &arrB, Long K)
{
    Long left = 1LL * arrA[0] + arrB[0], right = 1LL * arrA.back() + arrB.back();
    while(left < right) {
        Long middle = left + (right - left + 1) / 2;
 
        countLess(arrA, arrB, middle) < K ? left = middle : right = middle - 1;
    }
 
    return left;
}

int main()
{
    FAST_IO;
    
    int N;
    Long K;
    cin>>N>>K;
    
    VI arrA(N), arrB(N);
    for(auto &it : arrA)
        cin>>it;

    for(auto &it : arrB)
        cin>>it;
    
    sort(ALL(arrA)), sort(ALL(arrB));

    cout<<binarySearch(arrA, arrB, K)<<"\n";
    return 0;
}
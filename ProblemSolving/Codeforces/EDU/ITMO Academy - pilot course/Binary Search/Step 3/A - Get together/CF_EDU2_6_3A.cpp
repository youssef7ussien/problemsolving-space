/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define EPS                     1e-6
#define FF                      first
#define SS                      second

typedef vector<pair<int, int>>  VII;


inline bool check(const VII &arr, double middle) {
    double minX = LLONG_MAX, maxX = LLONG_MIN;
    for(auto &it : arr) {
        maxX = max(maxX, 1.0 * it.FF - it.SS * middle);
        minX = min(minX, 1.0 * it.FF + it.SS * middle);
    }

    return maxX <= minX;
}

double binarySearch(const VII &arr)
{
    double left = 0, right = 1e13;
    while(right - left > EPS) {
        double middle = (left + right) / 2;

        check(arr, middle) ? right = middle : left = middle;
    }

    return right;
}

int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    VII arr(N);
    for(auto &it : arr)
        cin>>it.FF>>it.SS;

    cout<<fixed<<binarySearch(arr)<<"\n";
    return 0;
}
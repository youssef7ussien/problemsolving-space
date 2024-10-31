/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef unsigned long long      Long;


inline bool check(int W, int H, int N, Long middle) {
    Long HH = middle / H;

    return HH != 0 && (middle / W) >= N / HH + (N % HH != 0);
}

Long binarySearch(int W, int H, int N)
{
    Long left = 1, right = 1e18;
    while(left < right) {
        Long middle = left + (right - left) / 2;

        check(W, H, N, middle) ? right = middle : left = middle + 1;
    }

    return right;
}

int main()
{
    FAST_IO;
    
    int W, H, N;
    cin>>W>>H>>N;
    
    cout<<binarySearch(W, H, N)<<"\n";
    return 0;
}
/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e18
typedef unsigned long long      Long;


Long binarySearch(int N, int X, int Y)
{
    if(X > Y)
        swap(X, Y);
    
    if(N == 1)
        return X;
    

    Long left = X, right = INF;
    while(left < right) {
        Long middle = left + (right - left) / 2;

        (middle / X) + (middle - X) / Y >= Long(N) ? right = middle : left = middle + 1;
    }

    return right;
}

int main()
{
    FAST_IO;
    
    int N, X, Y;
    cin>>N>>X>>Y;
    
    cout<<binarySearch(N, X, Y)<<"\n";
    return 0;
}
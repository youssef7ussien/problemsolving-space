/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define EPS                     1e-6


double binarySearch(double C)
{
    double left = 0, right = 1e10;
    while(right - left > EPS) {
        double middle = (left + right) / 2;

        middle * middle + sqrt(middle) >= C ? right = middle : left = middle;
    }

    return right;
}

int main()
{
    FAST_IO;
    
    double C;
    cin>>C;
    
    cout<<fixed<<setprecision(10)<<binarySearch(C)<<"\n";
    return 0;
}
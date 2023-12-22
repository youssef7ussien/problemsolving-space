/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Thursday, 07 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define A                       first
#define B                       second
#define INF                     1e12
#define EPS                     1e-6

typedef vector<pair<int, int>>  VII;


bool check(const VII &arr, int K, double middle) {
    vector<double> temp(LEN(arr));
    for(int i = 0 ; i < LEN(arr) ; i++)
        temp[i] = arr[i].A - arr[i].B * middle;
    
    sort(R_ALL(temp));

    return accumulate(temp.begin(), temp.begin() + K, 0.0) >= 0;   
}

double binarySearch(const VII &arr, int K)
{
    double left = 0, right = INF;
    while(right - left > EPS) {
        double middle = (left + right) / 2;
        check(arr, K, middle) ? left = middle : right = middle;
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
        cin>>it.A>>it.B;

    cout<<fixed<<setprecision(10)<<binarySearch(arr, K)<<"\n";
    return 0;
}
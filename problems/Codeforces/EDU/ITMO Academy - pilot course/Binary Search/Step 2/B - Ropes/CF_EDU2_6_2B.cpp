/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define EPS                     1e-6
typedef vector<int>             VI;


inline bool check(const VI &arr, int K, double middle) {
    int counter = 0;
    for(auto &it : arr)
        counter += floor(it / middle);

    return counter >= K;   
}

double binarySearch(const VI &arr, int K)
{
    double left = 0, right = 1e8;
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
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;

    cout<<fixed<<binarySearch(arr, K)<<"\n";
    return 0;
}
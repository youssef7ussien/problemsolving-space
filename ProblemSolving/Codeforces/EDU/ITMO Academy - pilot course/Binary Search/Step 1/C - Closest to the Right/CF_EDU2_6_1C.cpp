/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;

int binarySearch(const VI &arr, int num)
{
    int left = 0, right = LEN(arr) - 1;
    while(left < right) {
        int middle = left + (right - left) / 2;

        arr[middle] < num ? left = middle + 1 : right = middle;
    }

    return arr[right] >= num ? right + 1 : LEN(arr) + 1;
}

int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;

    while(K--) {
        int num;
        cin>>num;

        cout<<(lower_bound(ALL(arr), num) - arr.begin() + 1)<<"\n";
        // or use 
        // cout<<binarySearch(arr, num)<<"\n";
    }
    
    return 0;
}
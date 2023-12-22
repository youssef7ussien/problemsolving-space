/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Wednesday, 06 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


bool check(const VI &arr, int cows, int middle)
{   
    int counter = 1, last = arr[0];
    for(int i = 1 ; i < LEN(arr) ; i++)
        if(arr[i] - last >= middle) {
            last = arr[i];
            if(++counter == cows)
                return true;
        }

    return false;
}

int binarySearch(const VI &arr, int cows)
{   
    int left = 0, right = arr.back() - arr[0];
    while(left < right) {
        int middle = left + (right - left + 1) / 2;
        check(arr, cows, middle) ? left = middle : right = middle - 1;
    }
 
    return left;
}

int main()
{
    FAST_IO;
    
    int N, cows;
    cin>>N>>cows;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;
        
    cout<<binarySearch(arr, cows)<<"\n";
    return 0;
}
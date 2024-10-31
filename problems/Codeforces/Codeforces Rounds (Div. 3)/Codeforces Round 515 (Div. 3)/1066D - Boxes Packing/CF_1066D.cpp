/**
 * Title: "Boxes Packing", Codeforces problem. 
 * Date: Thursday, 30 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


bool check(const VI &arr, int M, int K, int middle) 
{
    int box = K;
    do {
        if(box < arr[middle]) {
            if(--M <= 0)
                return false;            
            box = K;
        }

        box -= arr[middle];
    } while(++middle < LEN(arr));

    return true;
}

int main()
{
    FAST_IO;
    
    int N, M, K;
    cin>>N>>M>>K;

    VI arr(N);
    for(auto &it : arr)
        cin>>it;

    int left = 0, right = N - 1;
    while(left < right) {
        int middle = left + (right - left) / 2;
        check(arr, M, K, middle) ? right = middle : left = middle + 1;
    }

    cout<<N - right<<"\n";
    return 0;
}
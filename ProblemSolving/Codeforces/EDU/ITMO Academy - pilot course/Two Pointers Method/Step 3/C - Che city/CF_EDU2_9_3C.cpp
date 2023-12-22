/**
 * Title: "Che city", Uncategorized problem. 
 * Date: Tuesday, 26 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N;
    Long R;
    cin>>N>>R;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;

    int left = 0, right = 1;
    Long result = 0;

    while(right < N) {
        if(arr[right] - arr[left] > R)
            result += (N - 1) - right + 1;

        while(left < right && arr[right] - arr[left] > R) {
            left++;

            if(arr[right] - arr[left] > R)
                result += (N - 1) - right + 1;
        }
        
        right++;
    }

    cout<<result<<"\n";
    return 0;
}
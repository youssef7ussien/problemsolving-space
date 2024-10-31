/**
 * Title: "Coprime Segment", Uncategorized problem. 
 * Date: Monday, 25 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define LEN(v)                  ((int)((v).size()))
typedef long long               Long;
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    // TODO: Not implemented yet.

    int N;
    cin>>N;
    
    vector<Long> arr(N);
    for(auto &it : arr)
        cin>>it;
    
    int left = 0, right = 0;
    Long result = 0;
    
    while(right < N) {
        while(__gcd(arr[left], arr[right]) == 1)
            left++;

        result += right - left + 1;
        right++;
    }
    
    cout<<result<<"\n";
    return 0;
}
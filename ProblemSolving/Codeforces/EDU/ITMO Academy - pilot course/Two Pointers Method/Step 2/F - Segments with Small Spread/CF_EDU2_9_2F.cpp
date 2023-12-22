/**
 * Title: "Segments with Small Spread", Uncategorized problem. 
 * Date: Sunday, 24 July 2022
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
    
    int N;
    Long K;
    cin>>N>>K;
    
    vector<Long> arr(N);
    for(auto &it : arr)
        cin>>it;
    
    multiset<Long> cnt;
    int left = 0, right = 0;
    Long result = 0;
    
    while(right < N) {
        cnt.insert(arr[right]);
        
        while(*cnt.rbegin() - *cnt.begin() > K)
            cnt.erase(cnt.find(arr[left++]));

        result += right - left + 1;
        right++;
    }
    
    cout<<result<<"\n";
    return 0;
}
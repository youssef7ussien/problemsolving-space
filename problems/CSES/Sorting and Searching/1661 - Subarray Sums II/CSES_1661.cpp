/**
 * Title: "Subarray Sums II", CSES problem. 
 * Date: Monday, 14 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO          ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long        Long;

int main()
{
    FAST_IO;
    
    int N, sum;
    cin>>N>>sum;
    
    vector<int> numbers(N);
    for (auto &it : numbers)
        cin>>it;

    Long prevSum = 0, counter = 0;
    map<Long, int> freq;
    for(int i = 0 ; i < N ; i++) {
        prevSum += numbers[i];
        counter += freq[prevSum - sum] + (prevSum == sum);
        freq[prevSum]++;
    }

    cout<<counter<<"\n";
    return 0;
}
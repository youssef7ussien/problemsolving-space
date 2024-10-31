/**
 * Title: "Longest k-Good Segment", Codeforces problem. 
 * Date: Monday, 21 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;

    VI numbers(N);
    for(auto &it : numbers)
        cin>>it;
    
    map<int, int> freq;
    int left = 0, right = 0, counter = 0;
    PII result = {1, 1};
    
    for(; right < N ; right++) {
        counter += (freq[numbers[right]]++ == 0);

        if(counter > K)
            counter -= (--freq[numbers[left++]] == 0);
        else if(right - left + 1 > result.second - result.first + 1)
            result = {left + 1, right + 1};
    }

    cout<<result.first<<" "<<result.second<<"\n";
    return 0;
}
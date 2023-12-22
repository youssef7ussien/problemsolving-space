/**
 * Title: "Consecutive Subsequence", Codeforces problem. 
 * Date: Monday, 15 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef pair<int, int>          PII;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    PII last;
    VI arr(N);
    map<int, int> LIS;
    
    for(auto &it : arr) {
        cin>>it;
        LIS[it] = LIS[it - 1] + 1;
        if(LIS[it] > last.second)
            last = {it, LIS[it]};
    }

    deque<int> result;
    for(int i = N - 1 ; i >= 0 ; i--)
        if(arr[i] == last.first)
            result.push_front(i + 1), last.first--;
    
    cout<<result.size()<<"\n";
    for(auto &it : result)
      cout<<it<<" ";
    cout<<"\n";

    return 0;
}
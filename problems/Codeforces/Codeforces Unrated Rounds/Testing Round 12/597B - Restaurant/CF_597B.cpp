/**
 * Title: "Restaurant", Codeforces problem. 
 * Date: Monday, 22 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
typedef vector<pair<int, int>>  VII;

int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    VII arr(N);
    for(auto &it : arr)
        cin>>it.SS>>it.FF;
    
    sort(ALL(arr));

    int current = 0, counter = 0;
    for(auto &it : arr)
        if(current < it.SS)
            counter++, current = it.FF;
            
    cout<<counter<<"\n";
    return 0;
}
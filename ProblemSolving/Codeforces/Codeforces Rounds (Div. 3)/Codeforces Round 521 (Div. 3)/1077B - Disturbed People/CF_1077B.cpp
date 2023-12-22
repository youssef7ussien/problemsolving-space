/**
 * Title: "Disturbed People", Codeforces problem. 
 * Date: Thursday, 31 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)       int T; cin>>T; while(T--)
#define FAST_IO             ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                 1e9

typedef long long           Long;
typedef vector<int>         VI;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    VI flats(N);
    for(auto &it : flats)
        cin>>it;
    
    int counter = 0;
    for(int i = 1 ; i < N - 1 ; i++)
        if(flats[i - 1] == 1 && flats[i] == 0 && flats[i + 1] == 1)
            counter++, flats[i + 1] = 0;
        
    cout<<counter<<"\n";
    return 0;
}
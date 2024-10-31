/**
 * Title: "Subarray Divisibility", CSES problem. 
 * Date: Wednesday, 16 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)               freopen(file, "r", stdin)
#define FILE_OUT(file)              freopen(file, "w", stdout)
#define INF                         1e9

typedef long long                   Long;
typedef vector<int>                 VI;


int main()
{
    #ifdef __DEBUG
        FILE_IN("samples\\__CSES_1662.in");
        FILE_OUT("samples\\__CSES_1662.out");
    #endif
    
    FAST_IO;
    
    int N;
    cin>>N;

    unordered_map<Long, int> mods;
    Long prefix = 0;
    
    mods[0]++;
    for(int i=0 ; i<N ; i++) {
        int temp; cin>>temp;
        prefix += temp;
        mods[(prefix % N + N) % N]++; // avoid negative prefix
    }

    Long counter = 0;
    for(auto &it : mods)
        if(it.second > 1)
            counter += ((Long)it.second * (it.second - 1)) / 2; // count number of ways.

    cout<<counter<<"\n";

    return 0;
}
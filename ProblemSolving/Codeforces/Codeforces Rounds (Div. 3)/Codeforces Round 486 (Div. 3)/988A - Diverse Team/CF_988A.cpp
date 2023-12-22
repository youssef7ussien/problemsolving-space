/**
 * Title: "Diverse Team", Codeforces problem. 
 * Date: Thursday, 03 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                     ((int)((v).size()))
#define LOOP(start, stop, steps)    for(int _i=start ; (steps>0 ? _i<stop : _i>stop) ; _i+=steps)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)               freopen(file, "r", stdin)
#define FILE_OUT(file)              freopen(file, "w", stdout)

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;


int main()
{
    #ifdef __DEBUG
        FILE_IN("samples\\__CF_988A.in");
        FILE_OUT("samples\\__CF_988A.out");
    #endif
    
    FAST_IO;
    
    int N, K;
    cin>>N>>K;

    unordered_map<int, int> check;

    LOOP(0, N, 1) {
        int temp; cin>>temp;
        if(check[temp] == 0)
            check[temp] = _i + 1;
    }

    if(SIZE(check) < K)
        cout<<"NO"<<"\n";
    else 
    {
        cout<<"YES"<<"\n";
    
        VII test(check.begin(), check.end());
        LOOP(0, K, 1)
            cout<<test[_i].second<<" ";
        cout<<"\n";
    }

    return 0;
}
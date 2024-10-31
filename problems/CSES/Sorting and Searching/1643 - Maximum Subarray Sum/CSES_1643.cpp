#include <bits/stdc++.h>

using namespace std;

#define CIN_TEMP(T)                 int T; cin>>T;
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9+5

typedef long long                   Long;
typedef vector<int>                 VI;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;

    Long prefix = 0, maxSum = -INF;

    for(int i=0 ; i<N ; i++) {
        CIN_TEMP(temp);
        prefix += temp;
        maxSum = max(maxSum, prefix);
        prefix = prefix < 0 ? 0 : prefix;
    }

    cout<<maxSum<<"\n";

    return 0;
}
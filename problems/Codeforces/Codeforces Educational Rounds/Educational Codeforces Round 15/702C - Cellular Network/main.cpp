#include <bits/stdc++.h>

using namespace std;

#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF               1e18

typedef long long         Long;
typedef vector<int>       VI;
typedef vector<Long>      VL;

int main()
{
    FAST_IO;

    int N, M;
    cin>>N>>M;

    VL cities(N), towers(M + 2);
    for(auto &it : cities)
        cin>>it;

    // To avoid Check if the left and right towers are not out of bound
    towers[0]=-INF, towers[M+1]=INF;
    for(int i=1 ; i<=M ; i++)
        cin>>towers[i];

    Long R=0;
    for(auto &it : cities)
    {
        auto rightTower=upper_bound(towers.begin(), towers.end(), it);
        auto leftTower=rightTower;
        leftTower--;

        R=max(R, min(*rightTower - it, it - *leftTower));
    }

    cout<<R<<"\n";

    return 0;
}
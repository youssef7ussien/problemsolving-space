// First solution

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int N,Q;

    cin>>N;

    vector<int> shops(N);
    for(auto &it : shops)
        cin>>it;

    cin>>Q;

    sort(shops.begin(), shops.end());

    for(int i=0 ; i<Q ; i++) {
        int coin; cin>>coin;
        cout<<(upper_bound(shops.begin(), shops.end(), coin) - shops.begin())<<"\n";
    }

    return 0;
}

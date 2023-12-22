// Second solution

#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())
typedef vector<int> Vector;

void print(const Vector &result) {
    for(auto &it : result)
        cout<<it<<"\n";
}

int binarySearch(const Vector &shops, int coin) {
    int left=0, right=SIZE(shops);

    while(left<right) {
        int middle=(left+right)/2;
        shops[middle]>coin ? right=middle : left=middle+1;
    }

    return right;
}

Vector calcNumberOfShops(Vector &shops,const Vector &coins) {

    sort(shops.begin(), shops.end());

    Vector result(SIZE(coins));
    for(int i=0 ; i<SIZE(coins) ; i++)
        result[i]=binarySearch(shops, coins[i]);

    return result;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int N,Q;
    cin>>N;
    Vector shops(N);
    for(auto &it : shops)
        cin>>it;

    cin>>Q;
    Vector coins(Q);
    for(auto &it : coins)
        cin>>it;

    print(calcNumberOfShops(shops, coins));

    return 0;
}

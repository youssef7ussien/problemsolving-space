#include <bits/stdc++.h>

using namespace std;
typedef long long Long;
#define SIZE(s) ((int)s.size())

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M;
    cin>>N>>M;

    set<Long> horizontals, verticals;

    while(M--) {
        int X, Y; cin>>X>>Y;

        horizontals.insert(X), verticals.insert(Y);

        cout<<(((Long)N - SIZE(horizontals)) * (N - SIZE(verticals)))<<" ";
    }

    return 0;
}

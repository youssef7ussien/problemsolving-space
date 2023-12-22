#include <bits/stdc++.h>

using namespace std;
typedef long long Long;

Long getMinNumMinutes(Long N)
{
    return N <= 6 ? 15 : 5 * ((N + N % 2) / 2);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin>>T;
    while(T--)
    {
        Long N;
        cin>>N;
        cout<<getMinNumMinutes(N)<<"\n";
    }

    return 0;
}

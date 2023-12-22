//solution: https://www.youtube.com/watch?v=tge-NMPdndc
#include <bits/stdc++.h>

using namespace std;

bool checkGame(int a, int b)
{
    int X = cbrt(1.0L * a * b);

    return 1LL*X*X*X != 1LL*a*b ? false : (a%X==0 && b%X==0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin>>N;

    while(N--)
    {
        int a, b; cin>>a>>b;
        cout<<(checkGame(a, b) ? "Yes" : "No")<<"\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define ALL(v)          ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)         ((int)((v).size()))
#define TEST_CASES(T)   int T; cin>>T; while(T--)

typedef long long Long;

int solve(int a, int b, int c)
{
    int diff = abs(a - b), maxNum = diff * 2;
    if(maxNum < max(a, b))
        return -1;

    return (c > maxNum ? -1 : c + diff <= maxNum ? c + diff : c - diff);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    TEST_CASES(T)
    {
        int a, b, c;
        cin>>a>>b>>c;

        cout<<solve(a, b, c)<<"\n";
    }
    return 0;
}

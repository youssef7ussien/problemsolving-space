#include <bits/stdc++.h>

using namespace std;

#define ALL(v)           ((v).begin()), ((v).end())
#define R_ALL(v)         ((v).rbegin()), ((v).rend())
#define SIZE(v)          ((int)((v).size()))
#define TEST_CASES(T)    int T; cin>>T; while(T--)
#define FAST_IO          ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE_IN(file)    freopen(file, "r", stdin)
#define FILE_OUT(file)   freopen(file, "w", stdout)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define INF 1e9

typedef long long Long;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;

Long GCD(Long a,Long b)
{
    if(b==0)
        return a;
    return GCD(b, a%b);
}

int main()
{
    FAST_IO;

    TEST_CASES(T)
    {
        Long X, cost=0, maxSize=0;

        TEST_CASES(N)
        {
            cin>>X;
            maxSize=GCD(maxSize, X), cost+=X;
        }

        cout<<cost<<" "<<maxSize<<"\n";
    }

    return 0;
}


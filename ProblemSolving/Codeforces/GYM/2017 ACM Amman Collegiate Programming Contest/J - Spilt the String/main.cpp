#include <bits/stdc++.h>

using namespace std;

#define ALL(v)          ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)         ((int)((v).size()))
#define TEST_CASES(T)   int T; cin>>T; cin.ignore(); while(T--)
#define FAST_IO          ios_base::sync_with_stdio(false), cin.tie(NULL)
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

bool checkValidSplit(const string &str,int value)
{
    int i=0;

    for(; i<SIZE(str) ; i+=value+1)
        if(i+value<SIZE(str) && str[i+value]!=' ')
            return false;

    return i-1 == SIZE(str);
}

bool solve(const string &str)
{
    VI spacesIndex;

    for(int i=0 ; i<SIZE(str) ; i++)
        if(str[i]==' ')
            spacesIndex.PB(i);

    for(auto it : spacesIndex)
        if(checkValidSplit(str, it))
            return true;

    return false;
}

int main()
{
    FAST_IO;

    TEST_CASES(T)
    {
        string str;
        getline(cin, str);

        cout<<(solve(str) ? "YES" : "NO")<<"\n";
    }

    return 0;
}


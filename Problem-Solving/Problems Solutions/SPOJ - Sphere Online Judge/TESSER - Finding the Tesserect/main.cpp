#include <bits/stdc++.h>

using namespace std;

#define ALL(v)          ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)         ((int)((v).size()))
#define TEST_CASES(T)   int T; cin>>T; while(T--)
#define FAST_IO          ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)    freopen(file, "r", stdin)
#define FILE_OUT(file)   freopen(file, "w", stdout)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define INF 1e9
#define TO_NUM(c) (c-'0')

typedef long long Long;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;

void failureFunction(VI &LPS,const string &str)
{
    for(int i=0, j=1 ; j<SIZE(str) ; j++)
    {
        while(i>0 && str[i]!=str[j])
            i=LPS[i-1];

        i+=(str[i]==str[j]);
        LPS[j]=i;
    }
}

char check(int a, int b)
{
    return ( a<b ? 'G' : (a>b ? 'L' : 'E'));
}

string convert(const VI &hills)
{
    string str;
    for(int i=1 ; i<SIZE(hills) ; i++)
        str+=check(hills[i-1], hills[i]);

    return str;
}

bool KMP(const string &str, const string &pat)
{
    VI LPS(SIZE(pat));

    failureFunction(LPS, pat);

    for(int i=0, j=1 ; j<SIZE(str) ; j++)
    {
        while(i>0 && pat[i]!=str[j])
            i=LPS[i-1];

        i+=(pat[i]==str[j]);

        if(i==SIZE(pat))
            return true;
    }

    return false;
}

int main()
{
    FAST_IO;

    TEST_CASES(T)
    {
        int N; string pat;

        cin>>N;

        VI hills(N);
        for(auto &it : hills)
            cin>>it;

        cin>>pat;

        cout<<(KMP(convert(hills), pat) ? "YES" : "NO")<<"\n";
    }

    return 0;
}

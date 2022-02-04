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


VI KMP(const string &str, const string &pat)
{
    VI LPS(SIZE(pat)), result;

    failureFunction(LPS, pat);

    int i=0;
    for(int j=0 ; j<SIZE(str) ; j++)
    {
        while(i>0 && pat[i]!=str[j])
            i=LPS[i-1];

        i+=(pat[i]==str[j]);
        if(i==SIZE(pat))
            result.PB(j-SIZE(pat)+1+1), i=LPS[i-1];
    }

    return result;
}

void print(const VI &result)
{
    if(SIZE(result)==0)
        { cout<<"Not Found\n\n"; return; }

    cout<<SIZE(result)<<"\n";
    for(auto it : result)
        cout<<it<<" ";
    cout<<"\n\n";
}

int main()
{
    FAST_IO;

    TEST_CASES(T)
    {
        string str, pat;

        cin>>str>>pat;

        print(KMP(str, pat));
    }

    return 0;
}

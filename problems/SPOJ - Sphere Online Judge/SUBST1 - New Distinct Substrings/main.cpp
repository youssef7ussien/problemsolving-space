#include <bits/stdc++.h>

using namespace std;

#define ALL(v)          ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)         ((int)((v).size()))
#define LOOP(i, n)      for(int i=0 ; i<(int)(n) ; i++)
#define lpi(i, j, n)    for(int i=(j) ; i<(int)(n) ; i++)
#define lpd(i, j, n)    for(int i=(j) ; i>=(int)(n) ; i--)
#define TEST_CASES(T)   int T; cin>>T; while(T--)
#define MP make_pair
#define PB push_back
#define INF 1e9
#define FAST_IO          ios_base::sync_with_stdio(false), cin.tie(NULL);
#define FILE_IN(file)    freopen(file, "r", stdin)
#define FILE_OUT(file)   freopen(file, "w", stdout)

typedef long long Long;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;

VI group;

struct Compare {
    int h;
    Compare(int h) : h(h) {}

    bool operator()(int a, int b) {
        return group[a] != group[b] ? group[a] < group[b] : group[a+h] < group[b+h];
    }
};

VI buildSuffixArray(const string &str)
{
    VI suffixes(SIZE(str)+1), sortedGroup(SIZE(str)+1);
    group.resize(SIZE(suffixes));

    for(int i=0 ; i<SIZE(suffixes) ; i++)
        suffixes[i]=i, group[i]=str[i];

    sort(ALL(suffixes), Compare(0));

    for(int h=1 ; sortedGroup[SIZE(suffixes)-1] != SIZE(suffixes)-1 ; h++)
    {
        sort(ALL(suffixes), Compare(h));

        for(int i=1 ; i<SIZE(suffixes) ; i++)
            sortedGroup[i]=sortedGroup[i-1]+Compare(h)(suffixes[i-1], suffixes[i]);

        for(int i=0 ; i<SIZE(suffixes) ; i++)
            group[suffixes[i]]=sortedGroup[i];
    }

    return suffixes;
}

VI buildLCP(const VI &suffixes,const string &str)
{
    VI LCP(SIZE(suffixes)), RA(SIZE(suffixes));

    for(int i=0 ; i<SIZE(RA) ; i++)
        RA[suffixes[i]]=i;

    int c=0;
    for(int i=0 ; i<SIZE(RA) ; i++)
    {
        if(RA[i])
        {
            int j=suffixes[RA[i] - 1];
            while(str[i+c] == str[j+c]) c++;
        }

        LCP[RA[i]] = c;
        c-=(c!=0);
    }

    return LCP;
}

int main()
{
    FAST_IO

    TEST_CASES(T)
    {
        string str;
        cin>>str;

        VI LCP=buildLCP(buildSuffixArray(str), str);

        int result=((Long)(SIZE(str)+1) * SIZE(str)) / 2;

        for(auto &it : LCP)
            result-=it;

        cout<<result<<"\n";
    }

    return 0;
}

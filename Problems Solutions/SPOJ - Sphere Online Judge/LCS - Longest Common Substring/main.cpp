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

VI group;

struct Compare {
    int h, n;
    Compare(int h, int n) : h(h), n(n) {}

    bool operator()(int a, int b)
    {
        return group[a]!=group[b] ? group[a]<group[b] : (a+h<n && b+h<n ? group[a+h]<group[b+h] : a>b);
    }
};

VI buildSuffixArray(const string &str)
{
    VI suffixes(SIZE(str)), sortedGroup(SIZE(str));
    group.resize(SIZE(suffixes));

    for(int i=0 ; i<SIZE(suffixes) ; i++)
        suffixes[i]=i, group[i]=str[i];

    sort(ALL(suffixes), Compare(0, SIZE(str)));

    for(int h=1 ; sortedGroup[SIZE(suffixes)-1]!=SIZE(suffixes)-1 ; h<<=1)
    {
        sort(ALL(suffixes), Compare(h, SIZE(str)));

        for(int i=1 ; i<SIZE(suffixes) ; i++)
            sortedGroup[i]=sortedGroup[i-1]+Compare(h, SIZE(str))(suffixes[i-1], suffixes[i]);

        for(int i=0 ; i<SIZE(suffixes) ; i++)
            group[suffixes[i]]=sortedGroup[i];
    }

    return suffixes;
}

VI buildLCP(const string &str,const VI &suffixes)
{
    VI LCP(SIZE(suffixes)), RA(SIZE(suffixes));

    for(int i=0 ; i<SIZE(LCP) ; i++)
        RA[suffixes[i]]=i;

    int c=0;
    for(int i=0 ; i<SIZE(LCP) ; i++)
    {
        if(RA[i])
        {
            int j=suffixes[RA[i]-1];
            while(str[i+c] == str[j+c])
                c++;
        }

        LCP[RA[i]]=c, c-=(c!=0);
    }

    return LCP;
}

int owner(int suffix,int sizeStr2) { return suffix>=sizeStr2 ? 2 : 1; }

int solve(const string &str,int sizeStr2)
{
    VI suffixes=buildSuffixArray(str);
    VI LCP=buildLCP(str, suffixes);

    int maxLCP=0;
    for(int i=1 ; i<SIZE(LCP) ; i++)
        if(owner(suffixes[i], sizeStr2) != owner(suffixes[i-1], sizeStr2) && LCP[i]>maxLCP)
            maxLCP=LCP[i];

    return maxLCP;
}

int main()
{
    FAST_IO;

    string temp, str;

    cin>>temp;
    str=temp+"$";
    cin>>temp;
    str+=temp;

    cout<<solve(str, SIZE(str) - SIZE(temp))<<"\n";

    return 0;
}

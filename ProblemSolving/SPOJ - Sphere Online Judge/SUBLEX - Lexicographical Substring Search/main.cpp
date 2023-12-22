#include <bits/stdc++.h>

using namespace std;

#define ALL(v)          ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define TEST_CASES(T)   int T; cin>>T; while(T--)
#define FAST_IO          ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE_IN(file)    freopen(file, "r", stdin)
#define FILE_OUT(file)   freopen(file, "w", stdout)
#define SZ(v)         ((int)((v).size()))
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
    int h;
    int n;
    Compare(int h, int n): h(h), n(n) {}

    bool operator()(int a,int b)
    {
        if(group[a]!=group[b])
            return group[a] < group[b];

        a+=h, b+=h;
        return (a<n && b<n ? group[a]<group[b] : a > b);
    }
};

VI buildSuffixArray(const string &str)
{
    VI suffixes(SZ(str)), sortedGroup(SZ(str));
    group.resize(SZ(suffixes), 0);

    for(int i=0 ; i<SZ(suffixes) ; i++)
        suffixes[i]=i, group[i]=str[i];

    sort(ALL(suffixes), Compare(0, SZ(str)));

    for(int h=1 ; sortedGroup[SZ(suffixes)-1] != SZ(suffixes)-1 ; h <<= 1)
    {
        sort(ALL(suffixes), Compare(h, SZ(str)));

        for(int i=1 ; i<SZ(suffixes) ; i++)
            sortedGroup[i] = sortedGroup[i-1] + Compare(h, SZ(str))(suffixes[i-1], suffixes[i]);

        for(int i=0 ; i<SZ(suffixes) ; i++)
            group[suffixes[i]]=sortedGroup[i];
    }

    return suffixes;
}

VI buildLCP(const string &str, const VI &suffixes)
{
    VI LCP(SZ(suffixes)), RA(SZ(suffixes));

    for(int i=0 ; i<SZ(suffixes) ; i++)
        RA[suffixes[i]]=i;

    int c=0;
    for(int i=0 ; i<SZ(suffixes) ; i++)
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

// create a cumulative array which store the number of distinct sub string till i'th rank suffix
VI buildCumArray(const VI &suffixes, const VI &LCP)
{
    VI cum(SZ(suffixes));

    cum[0]=SZ(suffixes)-suffixes[0];

    for(int i=1 ; i<SZ(suffixes) ; i++)
        cum[i]=cum[i-1] + (SZ(suffixes) - suffixes[i] - LCP[i]);

    return cum;
}

int main()
{
    FAST_IO

    string str;
    cin>>str;

    VI suffixes=buildSuffixArray(str);
    VI LCP=buildLCP(str, suffixes);
    VI cum=buildCumArray(suffixes, LCP);

    TEST_CASES(T)
    {
        Long K;
        cin>>K;

        int start=lower_bound(ALL(cum), K) - cum.begin();
        cout<<str.substr(suffixes[start], K-(start==0 ? 0 : cum[start-1])+LCP[start])<<"\n";
    }
    return 0;
}


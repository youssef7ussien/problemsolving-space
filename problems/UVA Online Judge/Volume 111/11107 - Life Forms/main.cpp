// hint: https://www.youtube.com/watch?v=Ic80xQFWevc&list=PLDV1Zeh2NRsCQ_Educ7GCNs3mvzpXhHW5&index=4
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)           ((v).begin()), ((v).end())
#define R_ALL(v)         ((v).rbegin()), ((v).rend())
#define SIZE(v)          ((int)((v).size()))
#define TEST_CASES(T)    int T; cin>>T; while(T--)
#define FAST_IO          ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)    freopen(file, "r", stdin)
#define FILE_OUT(file)   freopen(file, "w", stdout)
#define MP               make_pair
#define PB               push_back
#define FF               first
#define SS               second
#define INF              1e9

typedef long long Long;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<Long> VLL;
typedef vector<PII> VII;

VI group;

struct Compare {
    int h, n;
    Compare(int h,int n) : h(h), n(n) {}

    bool operator()(int a,int b)
    {
        return (group[a]!=group[b] ? group[a]<group[b] : (a+h<n && b+h<n ? group[a+h]<group[b+h] : a > b));
    }
};

VI buildSuffixArray(const string &str)
{
    VI suffixes(SIZE(str)), sortedGroup(SIZE(str));
    group.resize(SIZE(suffixes), 0);

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
            while(str[i+c] == str[j+c] && str[i+c]!='$')
                c++;
        }

        LCP[RA[i]]=c, c-=(c!=0);
    }

    return LCP;
}

int owner(int suffix,const VI &sizesStr)
{
    int sum=0, index=0;
    for(int i=0 ; i<SIZE(sizesStr) && suffix>=sum ; i++)
        sum+=sizesStr[i]+1, index++;

    return index-1;
}

pair<int, VI> getLCS(const VI &suffixes,const VI &LCP,const string &str,const VI &sizesStr)
{
    int maxLCP=0, uniqueOwner=0, low=SIZE(sizesStr)-1, heigh=SIZE(sizesStr)-1;
    VI ownerCount(SIZE(sizesStr)), indexLCS;

    // Window Sliding Technique
    while(heigh <= SIZE(str))
    {
        // slide heigh
        if(uniqueOwner*2<=SIZE(sizesStr))
        {
            uniqueOwner+=(heigh < SIZE(suffixes) && ++ownerCount[owner(suffixes[heigh], sizesStr)] == 1);
            heigh++;
            continue;
        }

        int minLCP=LCP[low+1], pos=low+1;
        for(int i=low+1 ; i<heigh ; i++)
            if(LCP[i] < minLCP)
                minLCP=LCP[i], pos=i;

        if(LCP[pos] > maxLCP)
            maxLCP=LCP[pos], indexLCS.clear();

        if(LCP[pos] == maxLCP)
            indexLCS.PB(pos);

        // slide low
        uniqueOwner-=(--ownerCount[owner(suffixes[low], sizesStr)] == 0);
        low++;

    }

    return {maxLCP, indexLCS};
}

void print(const VI &suffixes,string &str,pair<int, VI> LCS)
{
    if(LCS.FF == 0)
        { cout<<"?\n"; return; }

    string prev = "";
    for(auto &it : LCS.SS)
    {
        string next = str.substr(suffixes[it], LCS.FF);
        if(next == prev)
            continue;
        prev=next;
        cout<<next<<"\n";
    }
}

void solve(string &str,const VI &sizesStr)
{
    VI suffixes=buildSuffixArray(str);
    VI LCP=buildLCP(str, suffixes);

    print(suffixes, str, getLCS(suffixes, LCP, str, sizesStr));
}

int main()
{
    FAST_IO;

    int T=0; bool first=true;
    while((cin>>T) && T>=1)
    {
        if(!first) cout<<"\n"; first=false;

        string str;
        VI sizesStr;

        while(T--)
        {
            string temp;
            cin>>temp;
            str+=temp+"$", sizesStr.PB(SIZE(temp));
        }
        str.pop_back();

        if(SIZE(sizesStr)==1)
            cout<<str<<"\n";
        else
            solve(str, sizesStr);
    }

    return 0;
}

/**
 * Solution by Suffix Array O(nlognlogn)
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)          ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)         ((int)((v).size()))
#define TEST_CASES(T)   int T; cin>>T; while(T--)
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

VI group;

struct Compare {
    int h;
    Compare(int h) : h(h) {}

    bool operator()(int a,int b)
    {
        return (group[a]!=group[b] ? group[a] < group[b] : group[a+h] < group[b+h]);
    }
};

VI buildSuffixArray(const string &str)
{
    VI suffixes(SIZE(str)+1), sortedGroup(SIZE(str)+1);
    group.resize(SIZE(suffixes), 0);

    for(int i=0 ; i<SIZE(suffixes) ; i++)
        suffixes[i]=i, group[i]=str[i];

    sort(ALL(suffixes), Compare(0));

    for(int h=1 ; sortedGroup[SIZE(suffixes)-1]!=SIZE(suffixes)-1 ; h<<=1)
    {
        sort(ALL(suffixes), Compare(h));
        for(int i=1 ; i<SIZE(suffixes) ; i++)
            sortedGroup[i]=sortedGroup[i-1] + Compare(h)(suffixes[i-1], suffixes[i]);

        for(int i=0 ; i<SIZE(suffixes) ; i++)
            group[suffixes[i]]=sortedGroup[i];
    }

    return suffixes;
}

/**
 * * Use with char*:
 *  strncmp(str1, str2, countChar):
 *      >> value < 0 => str1 is less than str2.
 *      >> value = 0 => str1 is equal to str2.
 *      >> value > 0 => str1 is greater than str2.
 *
 * -------------------------------------------------------------------
 * * Use with string:
 *
 * str1.Compare(index1, countChar1, str2, index2, countChar2)
 *      >> value < 0 => str1 is less than str2.
 *      >> value = 0 => str1 is equal to str2.
 *      >> value > 0 => str1 is greater than str2.
 */

bool stringMatching(const string &str, const string &query,const VI &suffixes)
{
    int left=0, right=SIZE(suffixes)-1;

    while(left<=right)
    {
        int middle=left+(right-left) / 2;
        int result=query.compare(0, SIZE(query), str, suffixes[middle], SIZE(query));

        if(result==0)
            return true;

        result < 0 ? right=middle-1 : left=middle+1;
    }

    return false;
}

int main()
{
    FAST_IO

    TEST_CASES(T)
    {
        string str;
        cin>>str;
        VI suffixes=buildSuffixArray(str);

        TEST_CASES(Q)
        {
            string query;
            cin>>query;

            cout<<(stringMatching(str, query, suffixes) ? "y" : "n")<<"\n";
        }
    }
    return 0;
}

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

vector<int> group;

struct Compare {
    int h;
    int n;
    Compare(int h, int n): h(h), n(n) {}

    bool operator()(int a,int b)
    {
        return (group[a]!=group[b] ? group[a]<group[b]
                : (a+h<n && b+h<n ? group[a+h]<group[b+h] : a > b));
    }
};

namespace SA_FAST {

    void initialize(vector<int> &suffixes,vector<int> &newSuffixes,vector<int> &sortedGroup,vector<int> &groupStart, const string &str)
    {
        //bucket sort on the first char of suffix
        for (int i=0 ; i<SIZE(suffixes) ; i++)
            //treat sortedGroup as head of linked list and newSuffixes as next
            newSuffixes[i] = sortedGroup[str[i]], sortedGroup[str[i]] = i;

        int numGroup = -1, j = 0;
        for (int i = 0; i < 128; i++)
        {
            //compute the groups and groupStart and starting suffixes
            if (sortedGroup[i] != -1) {
                groupStart[++numGroup] = j;

                int cur = sortedGroup[i];  // cur = head
                while (cur != -1) {
                    suffixes[j++] = cur;
                    group[cur] = numGroup;
                    cur = newSuffixes[cur];  // cur->next
                }
            }
        }
    }

    vector<int> buildSuffixArray(const string &str)
    {
        vector<int> suffixes(SIZE(str)+1),
        newSuffixes(SIZE(suffixes)),
                    sortedGroup(SIZE(suffixes) > 128 ? SIZE(suffixes) : 128, -1),
                    groupStart(SIZE(suffixes));

        group.resize(SIZE(suffixes));

        initialize(suffixes, newSuffixes, sortedGroup, groupStart, str);

        sortedGroup[0]=sortedGroup[SIZE(suffixes)-1]=0;
        newSuffixes[0] = suffixes[0];

        // Loop until the number of groups = number of suffixes
        for(int h=1 ; sortedGroup[SIZE(suffixes)-1]!=SIZE(suffixes)-1 ; h<<=1)
        {
            // sort using 2h in the array newSuffixes
            for(int i=0 ; i<SIZE(suffixes) ; i++)
            {
                int j=suffixes[i]-h;
                if(j<0)
                    continue;
                newSuffixes[groupStart[group[j]]++] = j;
            }

            // compute the 2h group data given h group data
            for(int i=1 ; i<SIZE(suffixes) ; i++)
            {
                sortedGroup[i]=sortedGroup[i-1] + Compare(h, SIZE(str))(newSuffixes[i-1], newSuffixes[i]);

                if(Compare(h, SIZE(str))(newSuffixes[i-1], newSuffixes[i]))
                    groupStart[sortedGroup[i]] = i;
            }

            // copy the data
            for(int i=0 ; i<SIZE(suffixes) ; i++)
                suffixes[i] = newSuffixes[i], group[suffixes[i]]=sortedGroup[i];
        }

        return suffixes;
    }

}

namespace SA_MEDIUM {

    VI buildSuffixArray(const string &str)
    {
        VI suffixes(SIZE(str)+1), sortedGroup(SIZE(str)+1);
        group.resize(SIZE(suffixes), 0);

        for(int i=0 ; i<SIZE(suffixes) ; i++)
            suffixes[i]=i, group[i]=str[i];

        sort(ALL(suffixes), Compare(0, SIZE(str)));

        for(int h=1 ; sortedGroup[SIZE(suffixes)-1]!=SIZE(suffixes)-1 ; h<<=1)
        {
            sort(ALL(suffixes), Compare(h, SIZE(str)));

            for(int i=1 ; i<SIZE(suffixes) ; i++)
                sortedGroup[i]=sortedGroup[i-1]+Compare(h, SIZE(suffixes))(suffixes[i-1], suffixes[i]);

            for(int i=0 ; i<SIZE(suffixes) ; i++)
                group[suffixes[i]]=sortedGroup[i];
        }

        return suffixes;
    }
}

void print(const VI &suffixes)
{
    for(int i=1 ; i<SIZE(suffixes) ; i++)
        cout<<suffixes[i]<<"\n";
}

int main()
{
    FAST_IO;

    string str;
    cin>>str;

    print(SA_FAST::buildSuffixArray(str)); // Get 100 points
//    print(SA_MEDIUM::buildSuffixArray(str)); // Get 100 points

    return 0;
}

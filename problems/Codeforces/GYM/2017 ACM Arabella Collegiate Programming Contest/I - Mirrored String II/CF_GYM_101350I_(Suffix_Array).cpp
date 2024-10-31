#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<Long>            VL;
typedef vector<PII>             VII;

VI group;

struct Compare {
    int h, n;
    Compare(int h,int n) : h(h), n(n) {}

    bool operator()(int a,int b) {
        return (group[a] != group[b] ? group[a] < group[b] 
                    : (a + h < n && b + h < n ? group[a + h] < group[b + h] : a > b));
    }
};

VI buildSuffixArray(const string &str)
{
    VI suffixes(LEN(str)), sortedGroup(LEN(str));
    group.resize(LEN(suffixes), 0);

    for(int i = 0 ; i < LEN(suffixes) ; i++)
        suffixes[i] = i, group[i] = str[i];

    sort(ALL(suffixes), Compare(0, LEN(str)));

    for(int h = 1 ; sortedGroup[LEN(suffixes) - 1] != LEN(suffixes) - 1 ; h <<= 1) {
        sort(ALL(suffixes), Compare(h, LEN(str)));

        for(int i = 1 ; i < LEN(suffixes) ; i++)
            sortedGroup[i] = sortedGroup[i - 1] + Compare(h, LEN(suffixes))(suffixes[i - 1], suffixes[i]);

        for(int i = 0 ; i < LEN(suffixes) ; i++)
            group[suffixes[i]] = sortedGroup[i];
    }

    return suffixes;
}

VI buildLCP(const string &str,const VI &suffixes)
{
    vector<bool> flags = {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0};
    VI LCP(LEN(suffixes)), RA(LEN(suffixes));

    for(int i = 0 ; i < LEN(LCP) ; i++)
        RA[suffixes[i]] = i;

    int c = 0;
    for(int i = 0 ; i < LEN(LCP) ; i++) {
        if(RA[i]) {
            int j = suffixes[RA[i] - 1];
            while(str[i + c] == str[j + c] && flags[str[i + c] - 'A'])
                c++;
        }

        LCP[RA[i]] = c, c -= (c != 0);
    }

    return LCP;
}

int onwer(int suffix, int sizeStr) {
    return suffix < sizeStr ? 1 : 2;
}

bool isPalindrome(const string &str) {
    int left = 0, right = LEN(str) - 1;

    while(left < right)
        if(str[left++] != str[right--])
            return false;

    return true;
}

int getLCS(const VI &suffixes, const VI &LCP, const string &str, int sizeStr)
{
    int maxLCP = -1, index = 0;
    for(int i = 1 ; i < LEN(str) ; i++) {
        if(onwer(suffixes[i], sizeStr) != onwer(suffixes[i - 1], sizeStr) 
            && LCP[i] > maxLCP && isPalindrome(str.substr(suffixes[i], LCP[i])))
            maxLCP = LCP[i], index = i;
    }

    return maxLCP == -1 ? 0 : maxLCP;
}

int solve(const string &str)
{
    string newStr = str + "$" + string(R_ALL(str));

    VI suffixes = buildSuffixArray(newStr);
    VI LCP = buildLCP(newStr, suffixes);

    return getLCS(suffixes, LCP, newStr, LEN(str));
}

int main()
{
    FAST_IO;

    TEST_CASES(T) {
        string str;
        cin>>str;

        cout<<solve(str)<<"\n";
    }

    return 0;
}


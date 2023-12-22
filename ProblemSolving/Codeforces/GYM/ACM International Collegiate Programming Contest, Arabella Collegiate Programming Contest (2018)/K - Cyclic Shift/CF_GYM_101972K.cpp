#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


bool solve(string str1, string str2)
{
    vector<pair<char,char>> diff;

    for(int i = 0 ; i < LEN(str1) ; i++)
        if(str1[i] != str2[i])
            diff.push_back({str1[i], str2[i]});

    if(LEN(diff) == 0)
        return true;

    for(int i = 1 ; i < LEN(diff) - 1 ; i++)
        if(diff[i].first != diff[i - 1].second)
            return false;

    return diff[0].first == diff.back().second;
}

int main()
{
    FAST_IO;

    TEST_CASES(T) {
        string str1,str2;

        cin>>str1>>str1>>str2;
        cout<<(solve(str1,str2) ? "YES" : "NO")<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

string solve(string str1,string str2)
{
    vector<pair<char,char>> diff;

    for(int i=0 ; i<SIZE(str1) ; i++)
        if(str1[i]!=str2[i])
            diff.push_back({str1[i],str2[i]});

    if(SIZE(diff)==0)
        return "YES";

    for(int i=1 ; i<SIZE(diff)-1 ; i++)
        if(diff[i].first!=diff[i-1].second)
            return "NO";
    return diff[0].first!=diff[SIZE(diff)-1].second ? "NO" : "YES";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin>>T;
    while(T--)
    {
        string str1,str2;

        cin>>str1>>str1>>str2;
        cout<<solve(str1,str2)<<"\n";
    }
    return 0;
}

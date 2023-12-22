#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

int lenLongestPalindrome(string str)
{
    string revStr=string(str.rbegin(), str.rend());
    vector<vector<int>> dp(SIZE(str)+1, vector<int>(SIZE(str)+1));

    for(int i=1 ; i<=SIZE(str) ; i++)
        for(int j=1 ; j<=SIZE(str) ; j++)
            if(str[i-1]==revStr[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);

    return dp[SIZE(str)][SIZE(str)];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    string str;
    cin>>T;
    cin.ignore();

    while(T--)
    {
        getline(cin, str);
        cout<<lenLongestPalindrome(str)<<"\n";
    }
    return 0;
}

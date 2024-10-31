#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())


int LCS(string str1, string str2) // Longest Common Subsequence
{
    vector<vector<int>> C(SIZE(str1)+1, vector<int>(SIZE(str2)+1));

    for(int i=1 ; i<=SIZE(str1) ; i++)
    {
        for(int j=1 ; j<=SIZE(str2) ; j++)
            if(str1[i-1]==str2[j-1])
                C[i][j]=C[i-1][j-1]+1;
            else
                C[i][j]=max(C[i-1][j], C[i][j-1]);
    }

    return C[SIZE(str1)][SIZE(str2)];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str1, str2;

    while(getline(cin, str1))
    {
        getline(cin, str2);
        cout<<LCS(str1, str2)<<"\n";
    }

    return 0;
}

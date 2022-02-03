/**
 * hint: https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
 * hint: https://www.youtube.com/watch?v=QkBMgL5ocjA
 */
#include <iostream>
#include <vector>

using namespace std;

int LCS(const string &str1,const string &str2) //Longest Common Subsequence
{
    vector<vector<int>> lengths(str1.size()+1);

    for(int i=0 ; i<=(int)str1.size() ; i++)
        lengths[i].resize(str2.size()+1);

    for(int i=1 ; i<=(int)str1.size() ; i++)
        for(int j=1 ; j<=(int)str2.size() ; j++)
        {
            if(str1[i-1]==str2[j-1])
                lengths[i][j]=lengths[i-1][j-1]+1;
            else
                lengths[i][j]=max(lengths[i-1][j],lengths[i][j-1]);
        }

    return lengths[str1.size()][str2.size()];
}

int main()
{
    string str1, str2;
    cin>>str1>>str2;
    cout<<LCS(str1,str2)<<endl;

    return 0;
}

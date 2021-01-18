#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
#define SIZE(v) ((int)v.size())
#define CHAR(c) (c-'a')

Long numSubString(const string &str1,const string &str2,const int &k)
{
    vector<vector<bool>> substringsA(26,vector<bool>(26));

    for(int i=0 ; i<=SIZE(str1)-k ; i++)
        substringsA[CHAR(str1[i+k-1])][CHAR(str1[i])]=true;

    Long counter=0;
    vector<Long> freq(26);

    for(int i=0 ; i<SIZE(str2) ; i++)
    {
        freq[CHAR(str2[i])]++;
        for(int j=0 ; j<26 ; j++)
            if(substringsA[CHAR(str2[i])][j])
                counter+=freq[j];
    }

    return counter;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
//    freopen("Input (Big test cases).txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int T=0;
    cin>>T;

    while(T--)
    {
        int k=0;  // N & M not used in this code
        string str1,str2;
        cin>>str1>>str1>>k>>str1>>str2;

        cout<<numSubString(str1,str2,k)<<endl;
    }
    return 0;
}

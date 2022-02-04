#include <bits/stdc++.h>

using namespace std;
#define SIZE(s) ((int)s.size())

void failureFunction(vector<int> &LPS, string str)
{
    for(int i=0, j=1 ; j<SIZE(str) ; j++)
    {
        while(i>0 && str[i]!=str[j])
            i=LPS[i-1];

        i+=(str[i]==str[j]);
        LPS[j]=i;
    }
}

int KMP(string str, string pat)
{
    vector<int> LPS(SIZE(pat)); // Longest proper prefix which is also suffix

    failureFunction(LPS, pat);

    int i=0;
    for(int j=0 ; j<SIZE(str) ; j++)
    {
        while(i>0 && pat[i]!=str[j])
            i=LPS[i-1];

        i+=(pat[i]==str[j]);
    }

    return i;
}

string extendToPalindrome(string str)
{
    string revStr=string(str.rbegin(), str.rend());

    int index=KMP(str, revStr);

    return (str+revStr.substr(index, SIZE(revStr)-index));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str;
    while(cin>>str)
        cout<<extendToPalindrome(str)<<"\n";

    return 0;
}

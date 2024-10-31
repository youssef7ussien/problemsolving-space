#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

bool isFound(const string &str, const string &pattern)
{
    int j=0;
    for(int i=0 ; i<SIZE(str)-1 ; i++)
        if(str[i]==pattern[j] && str[i+1]==pattern[j+1])
            j+=2, i++;

    return j==SIZE(pattern);
}

int main()
{
    string str;
    cin>>str;

    cout<<(isFound(str, "ABBA") || isFound(str, "BAAB") ? "YES" : "NO")<<"\n";

    return 0;
}

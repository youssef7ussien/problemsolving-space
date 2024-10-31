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

string getPassword(string str)
{
    vector<int> LPS(SIZE(str)); // Longest proper prefix which is also suffix
    failureFunction(LPS, str);

    int index=LPS[SIZE(str)-1];
    while(index>0)
    {
        for(int i=0 ; i<SIZE(str)-1 ; i++)
            if(LPS[i]==index)
                return str.substr(0, index);

        index=LPS[index-1];
    }

    return "Just a legend";

}

int main()
{
    string str;
    cin>>str;

    cout<<getPassword(str)<<"\n";

    return 0;
}

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

int calc(int sizeStr,int lastLPS)
{
    return lastLPS!=0 && sizeStr%(sizeStr-lastLPS)==0 ? sizeStr/(sizeStr-lastLPS) : 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str;

    while((cin>>str) && str!="*")
    {
        vector<int> LPS(SIZE(str)); // Longest proper prefix which is also suffix

        failureFunction(LPS, str);

        cout<<calc(SIZE(str), LPS[SIZE(str)-1])<<"\n";
    }

    return 0;
}

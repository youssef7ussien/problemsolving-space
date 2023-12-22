#include <bits/stdc++.h>

using namespace std;

#define TO_NUM(c) ((int)(c-'0'))

string getMaxNum(string str, int K)
{
    for(int i=0 ; i<str.size() ; i++)
    {
        int index=i;

        for(int j=i+1 ; j<str.size() ; j++)
            if(K < j-i)
                break;
            else if(TO_NUM(str[index]) < TO_NUM(str[j]))
                index=j;

        K-=index-i;

        for(int j=index ; j>i ; j--)
            swap(str[j], str[j-1]);

    }

    return str;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str;
    int K;
    cin>>str>>K;

    cout<<getMaxNum(str, K)<<"\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

int main()
{
    string str;
    int M;

    cin>>str>>M;

    vector<int> sum(SIZE(str)/2+1);

    for(int i=0 ; i<M ; i++)
    {
        int from; cin>>from;
        sum[from]++;
    }

    for(int i=1 ; i<=SIZE(str)/2 ; i++)
    {
        sum[i]+=sum[i-1];
        if(sum[i]%2 != 0)
            swap(str[i-1], str[(SIZE(str)-i+1)-1]);
    }

    cout<<str<<"\n";

    return 0;
}

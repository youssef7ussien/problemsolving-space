#include <bits/stdc++.h>

using namespace std;

#define SIZE(v) ((int)v.size())

int getIndex(const vector<int> &arr)
{
    if(arr[0]!=arr[1] && arr[1]==arr[2])
        return 1;

    int index=0, prev=0;
    for(int i=1 ; i<SIZE(arr)-1 ; i++)
    {
        if(arr[i]!=arr[i-1] && arr[i-1]==arr[i+1])
            return i+1;
    }

    if(arr[SIZE(arr)-1]!=arr[SIZE(arr)-2] && arr[SIZE(arr)-2]==arr[SIZE(arr)-3])
        return SIZE(arr);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int T; cin>>T;
    while(T--)
    {
        int N; cin>>N;

        vector<int> arr(N);
        for(auto &it : arr)
            cin>>it;

        cout<<getIndex(arr)<<"\n";
    }
    return 0;
}

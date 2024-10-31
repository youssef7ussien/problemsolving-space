#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

int maxNumberBooks(const vector<int> &books, int time)
{
    int result=0, left=0, right=0, sum=0;

    while(right < SIZE(books))
    {
        sum+=books[right];
        if(sum <= time)
            result=max(result, right-left+1);

        while(sum > time)
            sum-=books[left++];
        right++;
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int N, T;
    cin>>N>>T;

    vector<int> books(N);
    for(auto &it : books)
        cin>>it;

    cout<<maxNumberBooks(books, T)<<"\n";

    return 0;
}

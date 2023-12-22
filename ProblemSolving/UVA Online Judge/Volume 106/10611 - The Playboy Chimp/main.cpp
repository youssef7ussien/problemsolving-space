// hint: Use BinarySearch
#include <iostream>
#include <vector>
using namespace std;

typedef long long Long;
#define SIZE(v) ((int)v.size())

string tallestHeightOnLeft(const vector<Long> &heightschimps,const Long &height)
{
    int left=0, right=SIZE(heightschimps)-1;
    while(left<=right)
    {
        int middle=left+(right-left)/2;

        heightschimps[middle]>=height ? right=middle-1 : left=middle+1;
    }
    return right<0 ? "X" : to_string(heightschimps[right]);
}

string shortestHeightOnRight(const vector<Long> &heightschimps,const Long &height)
{
    int left=0, right=SIZE(heightschimps)-1;
    while(left<=right)
    {
        int middle=left+(right-left)/2;

         heightschimps[middle]<=height ? left=middle+1 : right=middle-1;
    }
    return  left>=SIZE(heightschimps) ? "X" : to_string(heightschimps[left]);
}

int main()
{
    int N, Q;
    cin>>N;

    vector<Long> heightsChimps(N);
    for(auto &it : heightsChimps)
        cin>>it;

    cin>>Q;
    while(Q--)
    {
        int heightLuchu;
        cin>>heightLuchu;
        cout<<tallestHeightOnLeft(heightsChimps,heightLuchu)
            <<" "<<shortestHeightOnRight(heightsChimps,heightLuchu)<<endl;
    }
    return 0;
}

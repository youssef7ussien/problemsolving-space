#include <iostream>
#include <vector>

using namespace std;
typedef long long Long;
#define SIZE(v) ((int)v.size())

Long numGroups(const vector<int> &points,const int &D)
{
    if(SIZE(points)<=2)
        return 0;

    Long counter=0; int left=0, right=1;

    while(right<SIZE(points))
    {
        if(left==right)
            right++;
        else if(points[right]-points[left]<=D)
            counter+=(Long)(1)*(right-left)*(right-left-1)/2, right++;
        else
            left++;
    }

    return counter;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int N, D;
    cin>>N>>D;

    vector<int> points(N);
    for(auto &it : points)
        cin>>it;

    cout<<numGroups(points,D)<<"\n";

    return 0;
}

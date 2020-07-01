#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int>nums;
    int x;
    cin>>x;
    auto it=nums.begin();
    for(int i=0;i<x;i++)
    {
        int y;  cin>>y;
        it=nums.emplace_hint(it,y);
    }
    it=++nums.begin();
    if(nums.size()==1)
        cout<<"NO"<<endl;
    else
    cout<<*it<<endl;
    return 0;
}

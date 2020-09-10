#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int ans=0,nums[3];
    for(int i=0;i<3;i++)
        cin>>nums[i];
    sort(nums,nums+3);
    cout<<nums[2]-nums[0]<<endl;

    return 0;
}

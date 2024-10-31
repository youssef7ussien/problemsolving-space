#include <iostream>

using namespace std;
#define MAX 4

int nextNum(float nums[])
{
    // check arithmetic progressions
    if(nums[1]-nums[0]==nums[3]-nums[2] && nums[3]-nums[2]==nums[2]-nums[1])
        return nums[3]+(nums[1]-nums[0]);

    // check geometric progressions
    float R = nums[1] / nums[0];
    if(nums[2]/nums[1]==R && nums[3]/nums[2]==R && R*nums[3]==(int)(R*nums[3]))
        return R*nums[3];

    return 42;
}

int main()
{
    float nums[MAX];
    for(int i=0 ; i<MAX ; i++)
        cin>>nums[i];

    cout<<nextNum(nums)<<"\n";

    return 0;
}

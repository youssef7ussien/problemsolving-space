#include<bits/stdc++.h>

using namespace std;

int minOperations(int A,int B)
{
    if(A==B)
        return 0;

    int counter=0, nums[]={2,3,5};
    for(int i=0 ; i<3 ; i++)
    {
        int temp=0;
        while(A%nums[i]==0)
            temp++, A/=nums[i];
        while(B%nums[i]==0)
            temp--, B/=nums[i];

        counter+=abs(temp);
    }

    return A!=B ? -1 : counter;
}

int main()
{

    int A,B;
    cin>>A>>B;

    cout<<minOperations(A,B)<<"\n";
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int s;  cin>>s;
    int *arr=new int[s],sum[2]={0},player=0;
    for(int i=0;i<s;i++)
        cin>>arr[i];
    for(int i=0,j=s-1;j>=i;)
    {
        if(arr[i]>arr[j])
            sum[player]+=arr[i++];
        else
            sum[player]+=arr[j--];
        player=!player;
    }
    cout<<sum[0]<<"  "<<sum[1]<<endl;
    return 0;
}

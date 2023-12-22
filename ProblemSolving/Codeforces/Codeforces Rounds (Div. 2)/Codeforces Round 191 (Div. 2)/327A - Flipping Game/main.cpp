#include <iostream>
using namespace std;
int main()
{
    int s; cin>>s;
	int *arr=new int[s],zero=0,sum=0,bigSum=0;
	for(int i=0 ; i<s ;i++)
    { cin>>arr[i]; sum+=arr[i]; }
	for(int i=0 ; i<s ;i++)
    {
        zero=0;
        for(int j=i ; j<s ;j++)
        {
            if(arr[j]==0) zero++;
            else zero--;
            bigSum=max(bigSum,zero+sum);
        }
    }
	cout<<bigSum<<endl;
    delete []arr;
    return 0;
}

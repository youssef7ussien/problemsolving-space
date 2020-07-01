#include <iostream>
using namespace std;
int main()
{
    int s; cin>>s;
    int *arr=new int[s] ;
    for(int i=0;i<s;i++)
        cin>>arr[i];
    for(int i=0;i<s-1;i++)
        for(int j=i+1;j<s;j++)
            if(arr[i]>arr[j])
            {
                int cpy=arr[i];
                arr[i]=arr[j];
                arr[j]=cpy;
            }
    for(int i=0;i<s;i++)
        cout<<arr[i]<<"  ";
    return 0;
}

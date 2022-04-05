#include <iostream>

using namespace std;

int main()
{
    int s,d; cin>>s>>d;
    int *arr=new int[s];
    for(int i=0;i<s;i++)
        cin>>arr[(s-d+i)%s];
    for(int i=0;i<s;i++)
        cout<<arr[i]<<" ";
    return 0;
}

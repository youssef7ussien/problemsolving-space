#include <iostream>
using namespace std;
int main()
{
    int s; cin>>s;
    int *arr=new int[s],counter=0;
    for(int i=0;i<s;i++)
        cin>>arr[i];
    for(int i=0;i<s-1;)
    {
        if(arr[i+2]==0)
            { i+=2; counter++; }
        else if(arr[i+1]==0)
            { i+=1; counter++; }
    }
    cout<<counter<<endl;
    return 0;
}

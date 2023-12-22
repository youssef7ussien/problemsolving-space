#include <iostream>
using namespace std;

int countNumber(int arr[],int num,int s)
{
    int counter=0;
    for(int i=0;i<s;i++)
        if(num==arr[i])
            counter++;
    return counter;
}
int main()
{
    int s;  cin>>s;
    int *arr=new int[s],counter;
    for(int i=0;i<s;i++)
        cin>>arr[i];
    int mxRepeatNum=0,repeat=0;
    for(int i=0;i<s;i++)
    {
        repeat=countNumber(arr,arr[i],s);
        if(mxRepeatNum<repeat) mxRepeatNum=repeat;
    }
    cout<<s-mxRepeatNum<<endl;
    return 0;
}

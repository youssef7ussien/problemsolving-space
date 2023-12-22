#include<iostream>
using namespace std;
int countNumber(int arr[],int n,int s)
{
    int counter=0;
    for(int i=0;i<s;i++)
        if(n==arr[i])
            counter++;
    return counter;
}
int main()
{
    int s;  cin>>s;
    int *arr=new int[s],counter=0;
    for(int i=0;i<s;i++)
        cin>>arr[i];
    for(int i=0;i<s;i++)
    {
        bool visited=0;
        for(int j=i-1;j>=0;j--)
            if(arr[j]==arr[i])
            { visited=1; break; }
        if(visited)
            continue;
        int temp=countNumber(arr,arr[i],s);
        counter+=temp/2;
    }
    cout<<counter<<endl;
    return 0;
}

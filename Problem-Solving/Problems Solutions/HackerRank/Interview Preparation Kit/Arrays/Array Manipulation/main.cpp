#include <iostream>
using namespace std;
int main()
{
    int s; cin>>s;
    int repeat,a,b;
    long long *arr=new long long[s+1]() , k , maxNumber=0 ;
    cin>>repeat;
    for(int l=0;l<repeat;l++)
    {
        cin>>a>>b>>k;
        arr[a-1]+=k;
        if(b<=s) arr[b]-=k;
        cout<<arr[a-1]<<"   "<<arr[b]<<endl;
    }
    k=0;
    for(int i=0;i<s;i++)
        cout<<arr[i]<<endl;
    for(int i=0;i<s;i++)
    { k+=arr[i];  if(maxNumber<k) maxNumber=k; }
    cout<<maxNumber<<endl;
    return 0;
}

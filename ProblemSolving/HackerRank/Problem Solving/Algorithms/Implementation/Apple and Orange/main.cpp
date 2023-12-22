#include <iostream>
using namespace std;
int main()
{
    int s,t,m,n,a,b,counter=0;
    cin>>s>>t>>a>>b>>m>>n;
    int *apple=new int[m],*orange=new int[n];
    for(int i=0;i<m;i++)
        cin>>apple[i];
    for(int i=0;i<n;i++)
        cin>>orange[i];
    for(int i=0;i<m;i++)
        apple[i]+=a;
    for(int i=0;i<n;i++)
        orange[i]+=b;
    for(int i=0;i<m;i++)
        if(apple[i]>=s && apple[i]<=t)
            counter++;
    cout<<counter<<endl;
    counter=0;
    for(int i=0;i<n;i++)
        if(orange[i]>=s && orange[i]<=t)
            counter++;
    cout<<counter<<endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
        int n,mn=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>=0)
            a[i]=-a[i]-1;
        if(a[i]<a[mn])
            mn=i;
    }
    if(n%2)
        a[mn]=-a[mn]-1;
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";

    return 0;
}

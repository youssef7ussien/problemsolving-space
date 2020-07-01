#include <iostream>
using namespace std;
void sortArray(int a[],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]<a[j])
            {
                int cpy=a[i];
                a[i]=a[j];
                a[j]=cpy;
            }
}
int main()
{
    int n; cin>>n;
    int *a=new int[n],sumOfCoins=0,sum=0;
    for(int i=0;i<n;i++)
       { cin>>a[i]; sumOfCoins+=a[i]; }
    sortArray(a,n);
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>sumOfCoins/2)
            { cout<<i+1<<endl; return 0; }
    }
    return 0;
}

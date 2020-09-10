#include <iostream>
using namespace std;
int main()
{
    int m,n,counter=0;
    cin>>n>>m;
    while(1)
    {
        if(m%2==0 && m>n)
            { m/=2; counter++; }
        else
            { m++; counter++; }
        if(m==n)
           { cout<<counter<<endl; return 0; }
    }
    return 0;
}

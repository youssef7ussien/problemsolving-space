#include <iostream>
using namespace std;
int main()
{
    int n,b,d,a,sum=0,times=0;
    cin>>n>>b>>d;
    while(n--)
    {
        cin>>a;
        if(a<=b)
            sum+=a;
        if(sum>d)
        { sum=0; times++; }
    }
    cout<<times<<endl;
    return 0;
}

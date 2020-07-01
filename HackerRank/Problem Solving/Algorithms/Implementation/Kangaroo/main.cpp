#include <iostream>
using namespace std;
int main()
{
    int x1,x2,v1,v2,jump1=0,jump2=0;
    cin>>x1>>v1>>x2>>v2;
    if(x2>x1 && v2>v1 )
        { cout<<"NO"<<endl; return 0;}
    else
        while(1)
        {
            if((x1+=v1)==(x2+=v2))
            { cout<<"YES"<<endl; return 0; }
            else if(x1>x2)
            { cout<<"NO"<<endl; return 0; }
        }
    return 0;
}

#include <iostream>

using namespace std;

int mod(int B,int P,int M)
{
    if(P==0) return 1;
    if(P%2==0)
    {
        int x=mod(B,P/2,M);
        return (x*x)%M;
    }
    else return (B%M*mod(B,P-1,M))%M;
}
int main()
{
    int B,P,M;
    while(cin>>B>>P>>M)
    {
        if(B%M==0)
            cout<<"0"<<endl;
        else
            cout<<mod(B,P,M)<<endl;
    }
    return 0;
}

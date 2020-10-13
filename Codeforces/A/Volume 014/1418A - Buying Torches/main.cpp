#include <iostream>
using namespace std;

typedef long long Long;

Long solve(const Long &x,const Long &y,const Long &k)
{
    return (y*k+k-1)/(x-1)+min((Long)1,(y*k+k-1)%(x-1))+k;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        Long x, y, k;
        cin>>x>>y>>k;
        cout<<solve(x,y,k)<<endl;
    }

    return 0;
}

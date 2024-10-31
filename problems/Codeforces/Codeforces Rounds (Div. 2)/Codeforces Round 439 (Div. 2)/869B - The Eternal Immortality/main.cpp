#include <iostream>

using namespace std;
typedef long long Long;

int lastDigit(Long a,Long b)
{
    if(a==b)
        return 1;
    if(b-a>=10)
        return 0;

    int result=1;
    for(Long i=a+1 ; i<=b ; i++)
        result=(result * (i % 10)) % 10;

    return result;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    Long a, b;
    cin>>a>>b;

    cout<<lastDigit(a, b)<<"\n";

    return 0;
}

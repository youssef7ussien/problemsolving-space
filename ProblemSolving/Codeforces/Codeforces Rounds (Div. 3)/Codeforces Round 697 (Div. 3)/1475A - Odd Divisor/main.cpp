#include <iostream>

using namespace std;
typedef long long Long;

bool oddDivisors(Long num)
{
    if((num&1)!=0)
        return true;

    while((num&1)==0)
        num>>=1;

   return  (num>1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        Long num;
        cin>>num;

        oddDivisors(num) ? cout<<"YES\n" : cout<<"NO\n";
    }

    return 0;
}

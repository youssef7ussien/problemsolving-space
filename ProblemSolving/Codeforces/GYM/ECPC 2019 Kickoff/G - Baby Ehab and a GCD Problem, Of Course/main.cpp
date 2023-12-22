#include <iostream>

using namespace std;
typedef long long Long;

Long GCD(Long a, Long b)
{
    if(b==0)
        return a;

    return GCD(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("gcd.in", "r", stdin);

    int T=0;
    cin>>T;

    Long result=0;

    while(T--)
    {
        Long L, R;
        cin>>L>>R;

        R>L ? result=1 : result=GCD(result, R);

        cout<<result<<endl;
    }

    return 0;
}

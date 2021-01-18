#include <iostream>
using namespace std;

int solve(int x)
{
    int num=x%10, digit=0;
    while(x>0)
        digit++, x/=10;

    return (10*(num-1))+digit*(digit+1)/2;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<solve(x)<<endl;
    }
    return 0;
}

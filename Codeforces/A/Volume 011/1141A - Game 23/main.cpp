#include <iostream>

using namespace std;

int main()
{
    int n=0 , m=0 , div=0 , steps=0 ;

    cin>>n>>m;

    if (m%n!=0) return cout<<"-1"<<endl,0;
    div=m/n;
    while (div%2==0)
    {
        div/=2;
        steps++;
    }
    while (div%3==0)
    {
        div/=3;
        steps++;
    }
    if (div==1) cout<<steps<<endl;
    else cout<<"-1"<<endl;

    return 0;
}

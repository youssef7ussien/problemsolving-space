#include <iostream>
using namespace std;

int main()
{
    int m,n;
    cin>>n>>m;
    if(min(m,n)%2==0)
        cout<<"Malvika"<<endl;
    else
        cout<<"Akshat"<<endl;
    return 0;
}

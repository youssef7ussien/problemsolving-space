#include <iostream>
using namespace std;
int main()
{
    long long n,x,ice,counter=0;
    char m;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
        cin>>m>>ice;
        if(x>=ice || m=='+' )
           { m=='+'? x+=ice : x-=ice; }
        else
            counter++;
    }
    cout<<x<<" "<<counter<<endl;
    return 0;
}

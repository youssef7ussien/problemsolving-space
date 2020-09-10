#include <iostream>
#include <string>
using namespace std;
int main()
{
    string chain1 , chain2 ;
    cin>>chain1>>chain2;
    for(int i=0;i<chain1.size();i++)
    {
        if(chain2[i]<'a')
            chain2[i]+=32;
        if(chain1[i]<'a')
            chain1[i]+=32;
    }
    if(chain1>chain2)
        cout<<"1"<<endl;
    else if(chain2>chain1)
        cout<<"-1"<<endl;
    else
        cout<<"0"<<endl;
    return 0;
}

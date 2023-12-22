#include <iostream>

using namespace std;

int main()
{
    // TODO: Not implemented yet.
    
    int numCups , numHole , numSwap;
    cin>>numCups>>numHole>>numSwap;
    bool cups[numCups]={0};
    for(int i=0 ; i<numHole ; i++)
    {
        int x;
        cin>>x;
        cups[x]=1;
    }
    int pos=1;
    if(cups[pos])
    { cout<<"1"<<endl; return 0; }
    for(int i=0 ; i<numSwap ; i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==pos)
            pos=y;
        else if(pos==y)
            pos=x;
        if(cups[pos])
            break;
    }
    cout<<pos<<endl;
    return 0;
}

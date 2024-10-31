#include <iostream>
using namespace std;
int main()
{
    int num,magnet,cpy,counter=1;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>magnet;
        if(cpy!=magnet && i>0)
            counter++;
        cpy=magnet;
    }
    cout<<counter<<endl;
    return 0;
}

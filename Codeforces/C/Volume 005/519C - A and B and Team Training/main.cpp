#include <iostream>
using namespace std;

int main()
{
    int XP,NB,counter=0;
    cin>>XP>>NB;
    while(XP && NB && XP+NB>=3)
    {
        if(XP>=NB)
            XP-=2,NB-=1;
        else
            XP-=1,NB-=2;
        counter++;
    }
    cout<<counter<<endl;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int limak , bob , counter=0 ;
    cin>>limak>>bob;
    while(1)
    {
        counter++;
        if((limak*=3)>(bob*=2))
        { cout<<counter<<endl; return 0; }
    }
    return 0;
}

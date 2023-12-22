#include <iostream>
using namespace std;

int main()
{
    char num;
    int counter=0;
    while(num!='\n')
    {
        num=getchar();
        if(num=='4' || num=='7')    counter++;
    }
    if(counter==4 || counter==7)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

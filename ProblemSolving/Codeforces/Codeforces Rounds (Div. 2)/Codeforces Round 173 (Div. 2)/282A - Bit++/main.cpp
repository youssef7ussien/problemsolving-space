#include <iostream>

using namespace std;

int main()
{
    char letter , opration ;
    int number , counter=0 ;
    cin>>number;
    for(int i=0 ; i<number;i++)
    {
        cin>>opration>>opration>>letter;
        if(opration=='+')
            counter++;
        else
            counter--;
    }
    cout<<counter<<endl;
    return 0;
}

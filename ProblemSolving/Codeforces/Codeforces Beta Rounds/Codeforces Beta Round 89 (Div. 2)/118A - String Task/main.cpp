#include <iostream>

using namespace std;

int main()
{
    char world[100] ;
    cin>>world;
    for(int i=0 ; world[i]!='\0' ; i++)
    {
        if(world[i]>=65 && world[i]<=90 )
            world[i]=world[i]+32;
        if(world[i]!='a' && world[i]!='o' && world[i]!='y' && world[i]!='e' && world[i]!='u' && world[i]!='i')
        cout<<"."<<world[i];
    }
    return 0;
}

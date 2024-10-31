#include <iostream>

using namespace std;

int main()
{
    char c;
    bool finded=false;
    while(c!='\n')
    {
        c=getchar();
        if(c=='H' || c=='Q' || c=='9')
            finded=true;
    }
    if(finded)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

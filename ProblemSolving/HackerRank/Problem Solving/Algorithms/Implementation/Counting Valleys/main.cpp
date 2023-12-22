#include <iostream>
using namespace std;
int main()
{
    int s,lvl=0,v=0;
    cin>>s;
    char x;
    for(int i=0;i<s;i++)
    {
        cin>>x;
        if(x=='D')
            lvl++;
        else
            lvl--;
        if (lvl==0 && x=='U')
            v++;
    }
    cout<<v<<endl;
    return 0;
}

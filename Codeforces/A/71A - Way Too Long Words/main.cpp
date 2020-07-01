#include <iostream>
#include <string>
using namespace std;
int main()
{
    int s;  cin>>s;
    string *world=new string[s];
    for(int i=0;i<s;i++)
        cin>>world[i];
    for(int i=0;i<s;i++)
    {
        if(world[i].size()>10)
            cout<<world[i][0]<<world[i].size()-2<<world[i][world[i].size()-1]<<endl;
        else
            cout<<world[i]<<endl;
    }
    return 0;
}

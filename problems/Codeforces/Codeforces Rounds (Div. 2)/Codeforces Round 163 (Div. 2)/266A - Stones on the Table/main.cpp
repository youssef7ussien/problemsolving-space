#include <iostream>
using namespace std;
int main()
{
    int num,counter=0;    char color,cpy;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>color;
        if(color==cpy && i>0)
            counter++;
        cpy=color;
    }
    cout<<counter<<endl;
    return 0;
}

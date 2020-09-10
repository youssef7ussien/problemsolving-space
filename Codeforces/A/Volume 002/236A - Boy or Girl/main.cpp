#include <iostream>

using namespace std;

int main()
{
    char name[100] ;
    int characters[28] , counter=0 ;
    cin>>name;
    for(int i=0 ; name[i]!='\0' ;i++)
    {
        bool repeater=true;
        if(i>0)
            for(int j=i-1 ; j>=0 ;j--)
            {
                if(name[i]==name[j])
                { repeater=false; break; }
            }
        if(repeater)
            counter++;
    }
    if(counter%2==0)
        cout<<"CHAT WITH HER!"<<endl;
    else
        cout<<"IGNORE HIM!"<<endl;

    return 0;
}

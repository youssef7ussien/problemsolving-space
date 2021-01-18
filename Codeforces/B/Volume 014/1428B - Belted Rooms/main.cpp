#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N, clockwise=0, anticlockwise=0, off=0;
        string str;
        cin>>N>>str;
        for(int i=0 ; i<(int)str.size() ; i++)
        {
            if(str[i]=='>')
                clockwise++;
            if(str[i]=='<')
                anticlockwise++;
            if(str[i]=='-' || str[(i+N-1)%N]=='-')
                off++;
        }
        (clockwise==0 || anticlockwise==0) ? cout<<N<<endl : cout<<off<<endl;
    }
    return 0;
}

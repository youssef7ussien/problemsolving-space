#include <iostream>
using namespace std;
int main()
{
    int rows ;
    bool error=true;
    cin>>rows;
    char **seats=new char*[rows];
    for(int i=0;i<rows;i++)
        seats[i]=new char[5];

    for(int i=0;i<rows;i++)
        for(int j=0;j<5;j++)
            cin>>seats[i][j];
    for(int i=0;i<rows;i++)
        for(int j=0;j<5;j+=3)
            if(seats[i][j]=='O' && seats[i][j+1]=='O' )
                { seats[i][j]=seats[i][j+1]='+'; error=false; i=rows+1; break; }
    if(error)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<5;j++)
                cout<<seats[i][j];
            cout<<endl;
        }
    }
    for(int i=0;i<rows;i++)
        delete []seats[i];
    delete []seats;

    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int num,A=0,D=0;
    char in;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>in;
        in=='A'? A++:D++;
    }
    if(A>D)
        cout<<"Anton"<<endl;
    else if(D>A)
        cout<<"Danik"<<endl;
        else
        cout<<"Friendship"<<endl;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int height , num , maxHeight , counter=0 ;
    cin>>num>>maxHeight;
    for(int i=0 ; i<num ; i++)
    {
        cin>>height;
        if(height>maxHeight)
            while(height>maxHeight)
                { height/=2; counter+=2; }
        else
            counter++;
    }
    cout<<counter<<endl;
    return 0;
}

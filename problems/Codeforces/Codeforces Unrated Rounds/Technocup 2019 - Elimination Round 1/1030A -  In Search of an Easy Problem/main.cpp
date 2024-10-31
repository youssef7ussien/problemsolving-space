#include <iostream>

using namespace std;

int main()
{
    int numPeople ;  bool opinions ;
    cin>>numPeople;
    for(;numPeople>0;numPeople--)
    {
        cin>>opinions;
        if(opinions)
            { cout<<"HARD"<<endl; return 0; }
    }
    cout<<"EASY"<<endl;
    return 0;
}

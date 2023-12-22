#include <iostream>

using namespace std;

int main()
{
    int percent , numDrinks ;
    float sum=0 ;
    cin>>numDrinks;
    for(int i=0 ; i<numDrinks ; i++)
    { cin>>percent;  sum+=percent; }
    cout<<(float)sum/numDrinks<<endl;
    return 0;
}

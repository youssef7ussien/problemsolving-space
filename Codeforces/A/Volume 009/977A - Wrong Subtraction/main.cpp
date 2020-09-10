#include <iostream>
using namespace std;
int main()
{
    int number , k;
    cin>>number>>k;
    for(int i=0 ;i<k ; i++)
    {
        if(number%10==0)
            number/=10;
        else
            number-=1;
    }
    cout<<number<<endl;
    return 0;
}

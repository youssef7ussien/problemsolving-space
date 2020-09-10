#include <iostream>
#include <cmath>
using namespace std;

bool tPrime(int num)
{
    if(num==2)
        return true;
    else if((num*num)%4==0 || num==1)
        return false;
    else
    {
        int i;
        for(i=3 ; i*i<num ; i+=2)
            if(num%i==0)
                return false;
        if(i*i>num)
            return true;
        else
            return false;
    }
}
int main()
{
    int input ;
    double realNum;
    cin>>input;
    while(input--)
    {
        cin>>realNum;
        long long num=sqrt(realNum);
        if( (num*num==realNum) && tPrime(num))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

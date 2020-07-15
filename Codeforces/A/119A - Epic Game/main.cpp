#include <iostream>

using namespace std;

int gcd(int number1 ,int number2)
{
    int gcd=1 , minNum=min(number1,number2);
    for(int i=1 ; i<=minNum ;i++)
    {
        if(number1%i==0 && number2%i==0)
        {
            gcd=max(gcd,i);
        }
    }
    return gcd;
}
int main()
{
    int simon , Antisimon , stones ; bool winner;
    cin>>simon>>Antisimon>>stones;
    while(true)
    {
        stones-=gcd(simon,stones);
        if(stones==0)
        { winner=false; break;}
        stones-=gcd(Antisimon,stones);
        if(stones==0)
        { winner=true; break;}
    }
    if(winner)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    int coins[3]={0,0,0};
    char coin1,coin2,mark;
    for(int i=0;i<3;i++)
    {
        cin>>coin1>>mark>>coin2;
        if(mark=='>')
            coins[coin1-65]++;
        else if(mark=='<')
            coins[coin2-65]++;
    }

    for(int i=0;i<2;i++)
        if(coins[i]==coins[i+1])
        { cout<<"Impossible"<<endl; return 0; }
    if(coins[0]==coins[2])
    { cout<<"Impossible"<<endl; return 0; }

    for(int i=0,j=0;i<3;i++)
        for(int k=0;k<3;k++)
            if(coins[k]==j)
            {
                cout<<char(k+65);
                j++; break;
            }
    return 0;
}

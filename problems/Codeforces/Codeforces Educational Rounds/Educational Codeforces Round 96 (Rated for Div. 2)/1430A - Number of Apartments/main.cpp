#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=0,threeRoom=0,fiveRoom=0,sevenRoom=0;
        cin>>n;

        while(n>0)
        {
            if(n%3==0)
                n-=3, threeRoom++;
            else if(n%5==0)
                n-=5, fiveRoom++;
            else if(n%7==0)
                n-=7, sevenRoom++;
            else
            {
                if(n-3>=0)
                    n-=3, threeRoom++;
                else if(n-5>=0)
                    n-=5, fiveRoom++;
                else if(n-7>=0)
                    n-=7, sevenRoom++;
                else
                    break;
            }
        }

        n==0 ? cout<<threeRoom<<" "<<fiveRoom<<" "<<sevenRoom<<endl : cout<<"-1"<<endl;
    }
    return 0;
}

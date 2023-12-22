#include <iostream>

using namespace std;

int countDivisors(long long num)
{
    int count=0;
    long long i=1;

    for(; i*i<num ; i++)
        if(num%i==0)
            count+=2;
    if(i*i==num)
        count++;

    return count;
}

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        long long L,U,P=0;
        int D=0;

        cin>>L>>U;
        for(long long i=L ;i<=U ; i++)
        {
            int temp=countDivisors(i);
            if(temp>D)
            {
                D=temp;
                P=i;
            }
        }
        cout<<"Between "<<L<<" and "<<U<<", "<<P<<" has a maximum of "<<D<<" divisors."<<endl;
    }
    return 0;
}

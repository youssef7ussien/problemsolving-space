#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000000
typedef long long Long;

bool primes[MAX];
int numDigitPrimes[MAX];

int digitsSum(int num)
{
    int sum=0;
    while(num)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}

void initial()
{
    memset(primes,true,sizeof(primes));
    primes[0]=primes[1]=false;

    //  Sieve of Eratosthenes : https://www.geeksforgeeks.org/sieve-of-eratosthenes/
    for(Long i=2 ; i*i<MAX ; i++)
    {
        if(primes[i])
            for(Long j=i*i ; j<MAX ; j+=i)
                primes[j]=false;
    }

    //Cumulative (Prefix) Sum
    numDigitPrimes[0]=numDigitPrimes[1]=0;
    numDigitPrimes[2]=1;
    for (int i=3 ; i<MAX ; i++)
    {
        if(primes[i] && primes[digitsSum(i)])
            numDigitPrimes[i]=numDigitPrimes[i-1]+1;
        else
            numDigitPrimes[i]=numDigitPrimes[i-1];
    }
}

int countDigitPrimes(Long fromNum,Long toNum)
{
    return numDigitPrimes[toNum]-numDigitPrimes[fromNum-1];
}

int main()
{
    initial();
    int N,fromNum,toNum;
    cin>>N;

    while(N--)
    {
        cin>>fromNum>>toNum;
        cout<<countDigitPrimes(fromNum,toNum)<<endl;
    }

    return 0;
}

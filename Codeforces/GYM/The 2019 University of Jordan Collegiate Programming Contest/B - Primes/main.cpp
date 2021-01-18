#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if(num<2)
        return false;
    if(num==2)
        return true;

    for (int i=2 ; i*i<=num ; i++)
        if(num%i==0)
            return false;

    return true;
}

int main()
{
    int n;
    cin>>n;
    isPrime(n-2) ? cout<<2<<" "<<n-2<<endl : cout<<"-1"<<endl;

    return 0;
}

// Another solution

/*
#include <iostream>
#include <vector>
using namespace std;

#define SIZE(v) ((int)v.size())

void sieve(vector<bool> &prime)
{
    prime[0]=prime[1]=false;
    for (int i=2 ; i*i<=SIZE(prime) ; i++)
        if(prime[i])
            for(int j=i*i ; j<=SIZE(prime) ; j+=i)
                prime[j]=false;
}

int main()
{
    int n;
    cin>>n;
    vector<bool> prime(n+1,true);

    sieve(prime);
    for(int i=2 ; i*i<SIZE(prime) ; i++)
        if(prime[n-i] && prime[i])
            { cout<<i<<" "<<n-i<<endl; return 0; }

    cout<<"-1"<<endl;
    return 0;
}*/


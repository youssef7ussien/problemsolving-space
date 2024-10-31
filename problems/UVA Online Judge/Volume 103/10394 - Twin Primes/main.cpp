#include <bits/stdc++.h>

using namespace std;
#define MAX 20000001

void sieve(vector<bool> &primes)
{
    for(int i=2 ; i*i<MAX ; i++)
        if(primes[i])
            for(int j=i*i ; j<MAX ; j+=i)
                primes[j]=false;
}

void createTwinPrimes(vector<int> &twinprimes)
{
    vector<bool> primes(MAX, true);
    sieve(primes);

    int index=1;
    for(int i=3 ; i<MAX ; i++)
        if(primes[i] && primes[i+2])
            twinprimes[index++]=i;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> twinprimes(MAX);

    createTwinPrimes(twinprimes);

    int num;
    while(cin>>num)
        cout<<"("<<twinprimes[num]<<", "<<twinprimes[num]+2<<")"<<"\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long Long;
#define SIZE(v) ((int)v.size())
#define MAX 1e6+1

vector<int> primes;

void sieve()
{
    vector<bool> isPrimes(MAX, true);

    for(Long i=2 ; i*i<MAX ; i++)
        if(isPrimes[i])
            for(Long j=i*i ; j<MAX ; j+=i)
                isPrimes[j]=false;

    for(int i=2 ; i<MAX ; i++)
        if(isPrimes[i])
            primes.push_back(i);
}

int binarySearch(int prime) // Return upper bound
{
    int left=0, right=SIZE(primes);

    while(left<right)
    {
        int middle=(left+right)/2;

        primes[middle] <= prime ? left=middle+1 : right=middle;
    }

    return left;
}

Long solve(int N)
{

    Long result=0;

    for(auto prime : primes)
    {
        if(N < prime)
            break;

        result-=(prime < N/2); // To remove add number to itself (2+2 || 3+3)

        result+=binarySearch(N-prime);
    }

    // "result/2" to remove similar pairs {(2, 7) || (7, 2)}
    return result/2;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    sieve();

    int N, i=1;
    while((cin>>N) && N!=0)
        cout<<"Case "<<i++<<": "<<solve(N)<<"\n";

    return 0;
}

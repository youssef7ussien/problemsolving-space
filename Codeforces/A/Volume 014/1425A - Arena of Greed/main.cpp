#include <iostream>
using namespace std;

typedef long long int Long;
#define IF(N) if((N%2==0 && (N/2)%2!=0) || N==4)

void compute(Long &N,Long &chanekCount)
{
    if(N==0)
        return;
    IF(N)
        N/=2, chanekCount+=N;
    else
        N--, chanekCount++;
}

Long solve(Long N)
{
    Long chanekCount=0;
    compute(N,chanekCount);
    while(N>0)
    {
        IF(N)
            N/=2, compute(N,chanekCount);
        else
            N--, compute(N,chanekCount);
    }
    return chanekCount;
}

int main()
{
    int T=0;
    cin>>T;
    while(T--)
    {
        Long N=0;
        cin>>N;
        cout<<solve(N)<<endl;
    }

    return 0;
}

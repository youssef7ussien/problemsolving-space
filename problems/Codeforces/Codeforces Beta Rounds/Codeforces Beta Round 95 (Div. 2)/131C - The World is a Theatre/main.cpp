#include <iostream>

using namespace std;

long long C(int N,int R) // nCr => Combinations
{
    if(N<R)
        return 0;

    long long ans=1;
    for(int i=0 ; i<R ; i++)
        ans=ans*(N-i)/(i+1);

    return ans;
}

int main()
{
    int n,m,t;
    cin>>n>>m>>t;

    long long numGroup=C(n+m,t)-C(n,t)-C(m,t);
    for(int i=1 ; i<=3 ; i++)
        numGroup-=C(n,i)*C(m,t-i);

    cout<<numGroup<<"\n";

/**
 * C(n+m,t)         => total ways
 * C(n,t)           => num of groups contain only 't' boys
 * C(m,t)           => num of groups contain only 't' girls
 * C(n,1)*C(m,t-1)  => num of groups contain only 1 boy and t-1 'girls'
 * C(n,2)*C(m,t-2)  => num of groups contain only 2 boy and t-2 'girls'
 * C(n,3)*C(m,t-3)  => num of groups contain only 3 boy and t-3 'girls'
 */

    return 0;
}

// To understand the problem go to: https://algorithmist.com/wiki/UVa_583_-_Prime_Factors
#include <iostream>
#include <vector>

using namespace std;

typedef long long Long;

vector<Long> primeFactors(Long G)
{
    vector<Long> F;

    for(Long i=2 ; i*i<=G ; i==2 ? i++ : i+=2)
        while(G%i==0)
        {
            G/=i;
            F.push_back(i);
        }

    if(G!=1)
        F.push_back(G);

    return F;
}

void printPrimes(const vector<Long> &F)
{
    if(!F.empty())
    {
        auto it=F.begin();
        for(; it!=F.end()-1 ; it++)
            cout<<*it<<" x ";
        cout<<*it;
    }
    cout<<endl;
}

int main()
{
    Long G;

    while(cin>>G && G!=0)
    {
        if(G<0)
            { cout<<G<<" = -1 x ";  G*=-1; }
        else
            cout<<G<<" = ";

        printPrimes(primeFactors(G));
    }
    return 0;
}

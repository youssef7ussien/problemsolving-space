#include <iostream>

using namespace std;

int main()
{
    int N,M;
    while((cin>>N>>M) && (N && M))
    {
        int i;
        long long fact=1,C=1;
        if(N-M>M)
        {
            i=(N-M)+1;
            for(int j=2;j<=M;j++)
                fact*=j;
        }
        else
        {
            i=M+1;
            for(int j=2;j<=N-M;j++)
                fact*=j;
        }
        for(;i<=N;i++)
            C*=i;
        cout<<N<<" things taken "<<M<<" at a time is "<<C/fact<<" exactly."<<endl;
    }
    return 0;
}

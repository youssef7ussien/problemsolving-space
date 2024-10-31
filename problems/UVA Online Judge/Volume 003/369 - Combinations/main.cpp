// To understand the problem go to: https://algorithmist.com/wiki/UVa_369_-_Combinations

#include <iostream>
using namespace std;

int main()
{
    int N,M;
    while((cin>>N>>M) && (N && M))
    {
        long long K=1,result=1;

        for(int i=0; i<min(N-M, M) ; i++)
        {
            result*=N-i;
            K*=i+1;
            if(result%K==0)
            {
                result=(result/K);
                K=1;
            }
        }
        cout<<N<<" things taken "<<M<<" at a time is "<<result<<" exactly."<<endl;
    }
    return 0;
}

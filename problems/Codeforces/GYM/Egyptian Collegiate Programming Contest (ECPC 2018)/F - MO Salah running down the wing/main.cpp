#include <iostream>
using namespace std;

int minNumberOfGoals(int N,int M,int X,int Y)
{
    return Y==0 && ((Y+X)*N-M)>0 ? -1 : max((Y+X)*N-M,0);
}

int main()
{
//    freopen("mosalah.in","r",stdin);
    int T=0;
    cin>>T;
    while(T--)
    {
        int N,M,X,Y;
        cin>>N>>M>>X>>Y;
        cout<<minNumberOfGoals(N,M,X,Y)<<endl;
    }

    return 0;
}

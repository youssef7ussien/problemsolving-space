#include <iostream>

using namespace std;

#define condition(X,Y,N) ((X)>=(N/2)+1 && Y>=(N/2))

int main()
{
    int T=0;
    cin>>T;
    while(T--)
    {
        int N, X, Y;
        cin>>N>>X>>Y;

        condition(X,Y,N) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    }
    return 0;
}

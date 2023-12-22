#include <iostream>

using namespace std;
#define MOD ((int)1e9+7)

int main()
{
    int X,Y,N;
    cin>>X>>Y>>N;

    int Fn[6]={X, Y, Y-X, -X, -Y, X-Y};

    (Fn[(N-1)%6]%MOD) < 0 ? cout<<MOD+(Fn[(N-1)%6]%MOD)<<"\n" : cout<<(Fn[(N-1)%6]%MOD)<<"\n";

    return 0;
}

#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T,N,K;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        N-K<=1 && N%2==0 ? cout<<"Ayoub"<<endl : cout<<"Kilani"<<endl;
    }
    return 0;
}

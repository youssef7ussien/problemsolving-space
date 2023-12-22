#include <iostream>

using namespace std;

int main()
{
    long long N,K;
    cin>>N>>K;
    K>N ? cout<<"10"<<endl : N%K==0 ? cout<<(N/K)*5<<endl : cout<<((N/K)+1)*5<<endl;
    return 0;
}

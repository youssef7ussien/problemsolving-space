#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long N,K;
        cin>>N>>K;
        cout<<K+(K-1)/(N-1)<<endl;
    }
    return 0;
}

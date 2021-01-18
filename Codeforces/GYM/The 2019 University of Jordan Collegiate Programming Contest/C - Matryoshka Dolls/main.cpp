#include <iostream>
using namespace std;

int main()
{
    int S, X, counter=1;
    cin>>S>>X;

    while(S/X)
        S/=X,counter++;

    cout<<counter<<"\n";

    return 0;
}

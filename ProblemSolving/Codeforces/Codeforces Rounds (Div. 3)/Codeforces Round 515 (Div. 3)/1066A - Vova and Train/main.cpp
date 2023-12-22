#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int i=0 ; i<t ;i++)
    {
        int L, v, l, r;
        cin>>L>>v>>l>>r;
        cout<<(L/v)-(r/v)+((l-1)/v)<<endl;
    }

    return 0;
}

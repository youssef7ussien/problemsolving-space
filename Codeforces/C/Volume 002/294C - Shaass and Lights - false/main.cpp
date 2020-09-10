#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<bool> lights(n,false);

    for(int i=0 ; i<m ; i++)
    {
        int pos;
        cin>>pos;
        lights[pos-1]=true;
    }

    for(int i=0 ; i<n ; i++)
    {
        cout<<lights[i]<<" ";
    }

    return 0;
}

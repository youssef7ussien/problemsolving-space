#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numPiles,numJuicy,sum=0;
    cin>>numPiles;
    vector<int>worms;
    for(int i=0;i<numPiles;i++)
    {
        int x;  cin>>x;
        sum+=x;
        worms.resize(sum,i+1);
    }
    cin>>numJuicy;
    for(int i=0;i<numJuicy;i++)
    {
        int juicy;  cin>>juicy;
        cout<<worms[juicy-1]<<endl;
    }
    return 0;
}

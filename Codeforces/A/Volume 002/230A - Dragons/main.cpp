#include <iostream>
#include <map>

using namespace std;

int main()
{
    int kirPower,numDragon;
    cin>>kirPower>>numDragon;
    multimap<int,int>dragons;
    auto it=dragons.begin();
    for(int i=0;i<numDragon;i++)
    {
        int x,y; cin>>x>>y;
        it=dragons.emplace_hint(it,x,y);
    }
    for(auto m:dragons)
    {
        if(kirPower<=m.first)
        { cout<<"NO"<<endl;  return 0; }
        kirPower+=m.second;
    }
    cout<<"YES"<<endl;
    return 0;
}

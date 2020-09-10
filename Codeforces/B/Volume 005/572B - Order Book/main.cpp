#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n,s;
    map<int,int> sell,buy;

    cin>>n>>s;

    for(int i=0 ; i<n ; i++)
    {
        char d; int p,q;
        cin>>d>>p>>q;

        if(d=='B')
            buy[p]+=q;
        else
            sell[p]+=q;
    }

    int i=0;
    for(auto it=sell.rbegin() ; it!=sell.rend() ; it++,i++)
    {
        if ( i+s>=(int)sell.size())
        cout<<"S "<<it->first<<" "<<it->second<<endl;
    }

    i=0;
    for(auto it=buy.rbegin() ; i!=s && it!=buy.rend() ; it++,i++)
        cout<<"B "<<it->first<<" "<<it->second<<endl;

    return 0;
}

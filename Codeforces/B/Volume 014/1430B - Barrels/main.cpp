#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int> barrels(n);

        for(auto &it : barrels)
            cin>>it;
        sort(barrels.rbegin(),barrels.rend());

        long long sum=0;
        for(int i=0 ; i<=k ; i++)
            sum+=barrels[i];

        cout<<sum<<endl;
    }
    return 0;
}

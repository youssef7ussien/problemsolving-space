#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int> arrA)
{
    int sum=0;
    for(auto it : arrA)
        sum+=it;

    if(sum==0)
        { cout<<"NO"<<endl; return; }

    sum>0 ? sort(arrA.begin(),arrA.end(),greater<int>()) : sort(arrA.begin(),arrA.end());

    cout<<"YES"<<endl;
    for(auto it : arrA)
        cout<<it<<" ";
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arrA(n);
        for(int i=0 ; i<n ; i++)
            cin>>arrA[i];
        solve(arrA);
    }
    return 0;
}

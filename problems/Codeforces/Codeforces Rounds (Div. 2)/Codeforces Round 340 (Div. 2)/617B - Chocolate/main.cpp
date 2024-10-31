#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, left=-1;
    cin>>n;

    vector<int> pieces(n);
    for(int i=0 ; i<n ; i++)
    {
        cin>>pieces[i];
        if(left==-1 && pieces[i])
            left=i;
    }

    if(left==-1)
    {
        cout<<"0\n";
        return 0;
    }

    long long ans=1, right=left;
    while(right<n)
        if(pieces[right++])
            ans*=right-left, left=right;

    cout<<ans<<"\n";

    return 0;
}

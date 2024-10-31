#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>fence(n+1);
    vector<int>sumPrevious(n);
    for(int i=1;i<=n;i++)
    {
        cin>>fence[i];
        fence[i]+=fence[i-1];
    }
    if(n==k)
    { cout<<"1"<<endl; return 0; }
    int minSum=fence[k]-fence[0],index=k+1;
    for(int i=k+1;i<=n;i++)
        if(minSum>fence[i]-fence[i-k])
        {
            minSum=fence[i]-fence[i-k];
            index=i+1;
        }

    cout<<index-k<<endl;
    return 0;
}

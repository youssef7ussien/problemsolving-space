#include <iostream>
#include <vector>

using namespace std;
typedef long long Long;
#define SIZE(v) ((int)v.size())

int findDominantPiranha(vector<Long> piranha)
{
    int maxIndex=0;
    bool founded=false;

    for(int i=1 ; i<SIZE(piranha)-1 ; i++)
        if(piranha[maxIndex]<=piranha[i] && (piranha[i]>piranha[i+1] || piranha[i]>piranha[i-1]))
                maxIndex=i, founded=true;

    if(maxIndex==0)
        founded=piranha[0]>piranha[1];

    if(piranha[maxIndex]<piranha[SIZE(piranha)-1] && piranha[SIZE(piranha)-1]>piranha[SIZE(piranha)-2])
        maxIndex=SIZE(piranha)-1, founded=true;

    return founded ? maxIndex+1 : -1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<Long> piranha(N);
        for(auto &it : piranha)
            cin>>it;
        cout<<findDominantPiranha(piranha)<<endl;
    }

    return 0;
}

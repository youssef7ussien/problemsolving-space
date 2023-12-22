#include <bits/stdc++.h>

using namespace std;

typedef long long Long;
#define SIZE(v) ((int)v.size())

bool isValid(vector<Long> souvenirs,const int &K, const Long &S,Long &T)
{
    for(int i=0 ; i<SIZE(souvenirs) ; i++)
        souvenirs[i]+=(Long)(i+1)*K;

    sort(souvenirs.begin(),souvenirs.end());

    Long sum=0;
    for(int i=0 ; i<K ; i++)
        sum+=souvenirs[i];

    if(sum<=S)
        { T=sum; return true; }
    return false;
}

void  maxSouvenirsNumber(const vector<Long> &souvenirs, const Long &S)
{
    int left=0, right=SIZE(souvenirs), K=0;
    Long T=0;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(isValid(souvenirs,middle,S,T))
            K=middle, left=middle+1;
        else
            right=middle-1;
    }

    cout<<K<<" "<<T<<"\n";
}

int main()
{
    int N;
    Long S;
    cin>>N>>S;

    vector<Long> souvenirs(N);
    for(auto &it : souvenirs)
        cin>>it;

    maxSouvenirsNumber(souvenirs,S);

    return 0;
}

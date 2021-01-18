#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> Pair;

void solve(const int &K,vector<Pair> &iceCreams)
{
    sort(iceCreams.begin(), iceCreams.end());

    int bestCalories=iceCreams[K-1].first, index=K;

    while(index<(int)iceCreams.size() && iceCreams[K-1].first==iceCreams[index].first) index++;

    sort(iceCreams.begin(), iceCreams.begin()+index, [](const Pair &a,const Pair &b){
        return a.second>b.second;
    });

    long long sumHappiness=0;
    for(int i=0 ; i<K ; i++)
        sumHappiness+=iceCreams[i].second;

    cout<<bestCalories<<" "<<sumHappiness<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
//    freopen("icecream.in","r",stdin);

    int T=0;
    cin>>T;
    while(T--)
    {
        int N,K;
        cin>>N>>K;

        vector<Pair> iceCreams(N);
        for(auto &it : iceCreams)
            cin>>it.first;
        for(auto &it : iceCreams)
            cin>>it.second;

        solve(K,iceCreams);
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

int maxNumTrees(const vector<pair<int, int>> &trees)
{
    if(SIZE(trees)<=2)
        return SIZE(trees);

    int counter=2, lastCut=trees[0].first;

    for(int i=1 ; i<SIZE(trees)-1 ; i++)
    {
        if(trees[i].first-trees[i].second > lastCut) // cut left
            counter++, lastCut=trees[i].first;
        else if(trees[i].first+trees[i].second < trees[i+1].first) // cut right
            counter++, lastCut=trees[i].first+trees[i].second;
        else
            lastCut=trees[i].first;
    }

    return counter;
}

int main()
{
    int N;
    cin>>N;

    vector<pair<int, int>> trees(N); // first = x , second = h

    for(auto &it : trees)
        cin>>it.first>>it.second;

    cout<<maxNumTrees(trees)<<"\n";

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define SIZE(v) ((int)v.size())
#define MAX 2e6+10

bool check(const vector<int> &cowbells, int K, int box)
{
    if(cowbells[SIZE(cowbells)-1] > box)
        return false;

    int left=0, right=SIZE(cowbells)-1, counter=0;

    while(left <= right)
        left+=(cowbells[left]+cowbells[right] <= box), right--, counter++;

    return counter<=K;
}

int smallestSize(const vector<int> &cowbells, int K)
{
    if(K > SIZE(cowbells))
        return cowbells[SIZE(cowbells)-1];

    int left=1, right=MAX;
    while(left<=right) {
        int middle=(left+right)/2;

        check(cowbells, K, middle) ? right=middle-1 : left=middle+1;
    }

    return left;
}

int main()
{
    int N, K;
    cin>>N>>K;

    vector<int> cowbells(N);
    for(auto &it : cowbells)
        cin>>it;

    cout<<smallestSize(cowbells, K)<<"\n";

    return 0;
}


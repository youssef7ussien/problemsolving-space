#include <bits/stdc++.h>

using namespace std;
#define SIZE(v) ((int)v.size())

int firstTrueBS(const vector<int> &elements, int value)
{
    int left=0, right=SIZE(elements);

    while(left<right) {
        int middle=(left+right)/2;
        elements[middle]>value ? right=middle : left=middle+1;
    }

    return right;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin>>N>>M;

    vector<int> first(N);
    for(auto &it : first)
        cin>>it;

    sort(first.begin(), first.end());

    for(int i=0 ; i<M ; i++) {
        int second; cin>>second;

        cout<<firstTrueBS(first, second)<<" ";
    }

    return 0;
}

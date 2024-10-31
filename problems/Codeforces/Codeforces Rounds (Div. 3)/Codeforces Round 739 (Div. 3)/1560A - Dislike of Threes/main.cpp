#include <bits/stdc++.h>

using namespace std;
#define TEST_CASES(T)   int T; cin>>T; while(T--)

void build(vector<int> &elements)
{
    for(int i=1 ; i<=1700 ; i++)
        if(i % 3 != 0 && i % 10 != 3)
            elements.push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> elements;

    build(elements);

    TEST_CASES(T)
    {
        int K;
        cin>>K;

        cout<<elements[K-1]<<"\n";
    }
    return 0;
}

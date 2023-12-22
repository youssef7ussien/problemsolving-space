#include <bits/stdc++.h>

using namespace std;

#define ALL(v)           ((v).begin()), ((v).end())
#define R_ALL(v)         ((v).rbegin()), ((v).rend())
#define SIZE(v)          ((int)((v).size()))
#define TEST_CASES(T)    int T; cin>>T; while(T--)
#define FAST_IO          ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FILE_IN(file)    freopen(file, "r", stdin)
#define FILE_OUT(file)   freopen(file, "w", stdout)

typedef long long Long;

int main()
{
    FAST_IO

    TEST_CASES(T)
    {
        int K;
        cin>>K;

        int near = ceil((double)sqrt(K)), middle = (near * near) - (near - 1);

        if(K <= middle)
            cout<<near - abs(K - middle)<<" "<<near<<"\n";
        else
            cout<<near<<" "<<near - abs(K - middle)<<"\n";
    }
    return 0;
}

// http://uva.outsbook.com/problemhints/problemdetails/100/10025
#include <bits/stdc++.h>

using namespace std;

#define arthimatic(n) (n*(n+1)/2)

int minPossibleN(int K)
{
    if(K==0)
        return 3;

    K=abs(K);

    int n=(int)sqrt(2 * K) - 1;

    for(; arthimatic(n) < K || (arthimatic(n)-K) % 2 == 1 ; n++);

    return n;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T;
    cin>>T;

    while(T--)
    {
        int K;
        cin>>K;

        cout<<minPossibleN(K)<<"\n"<<(T!=0 ? "\n" : "");
    }

    return 0;
}

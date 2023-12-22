#include <bits/stdc++.h>

using namespace std;

int formula(int K)
{
    return ((pow(2, K)-1) * pow(2, K-1));
}

int solve(int N)
{
    int result=0;
    for(int i=15 ; i>=1 ; i--)
    {
        long long result = formula(i);

        if(N%result == 0)
            return result;
    }

    return result;
}

int main()
{
    int N;
    cin>>N;

    cout<<solve(N)<<"\n";

    return 0;
}

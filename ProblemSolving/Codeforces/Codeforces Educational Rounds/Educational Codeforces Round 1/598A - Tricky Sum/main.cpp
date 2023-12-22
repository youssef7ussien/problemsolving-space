#include <bits/stdc++.h>

using namespace std;
typedef long long Long;

// Sum numbers in range(num_1 : num_n)
Long arithmeticFormula(Long num_1, Long num_n, Long n)
{
    return (((num_1 + num_n) * n) / 2);
}

Long trickySum(Long num)
{
    Long result = arithmeticFormula(1, num, num);

    // subtract all powers of two (twice)
    for(int i=1 ; i<=num ; i*=2)
        result -= i*2;

    return result;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin>>T;

    while(T--)
    {
        Long num; cin>>num;

        cout<<trickySum(num)<<"\n";
    }

    return 0;
}

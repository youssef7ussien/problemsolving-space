#include <bits/stdc++.h>

#define FAST_IO             std::ios_base::sync_with_stdio(false), std::cin.tie(NULL)

typedef long long           Long;
typedef std::vector<int>    VI;
typedef std::map<int, int>  MII;

int main()
{
    FAST_IO;

    int N;
    std::cin>>N;

    VI numbers(N);
    MII freqNumbers;
    for(auto &it : numbers)
    {
        std::cin>>it;
        freqNumbers[it]++;
    }

    Long result = 0;
    for(auto &it : numbers)
        for(int i=1 ; i<31 ; i++)
        {
            Long power = std::pow(2, i);
            result += ((power - it == it) ? freqNumbers[it]-1 : freqNumbers[power - it]);
        }

    std::cout<<result/2<<"\n";

    return 0;
}

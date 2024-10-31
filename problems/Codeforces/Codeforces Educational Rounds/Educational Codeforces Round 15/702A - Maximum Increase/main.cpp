#include <bits/stdc++.h>

#define FAST_IO           std::ios_base::sync_with_stdio(false), std::cin.tie(NULL)

int main()
{
    FAST_IO;

    int N, number, counter = 1, maxLength = 1;
    
    std::cin>>N>>number;

    for(int i=1 ; i<N ; i++)
    {
        int temp = number;
        std::cin>>number;

        if(number>temp)
            counter++;
        else
            maxLength = std::max(maxLength, counter), counter = 1;
    }

    std::cout<<std::max(maxLength, counter)<<"\n";
    return 0;
}

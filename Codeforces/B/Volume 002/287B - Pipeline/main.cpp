// https://www.youtube.com/watch?v=mhrz7F01Vqs
#include <iostream>

using namespace std;
typedef long long Long;

// sum numbers 1+2+3+...+N
Long sum(Long N)
{
    return (N*(N+1)/2);
}

Long sum(Long from,Long to)
{
    return from<=1 ? sum(to) : sum(to)-sum(from-1);
}

Long minSplitters(Long N,Long K) // BinarySearch
{
    Long left=1,right=K;
    while(left<right)
    {
        Long middle=left+(right-left)/2;
        Long result=sum(middle,K);

        if(result==N)
            return K-middle+1;
        result>N ? left=middle+1 : right=middle;
    }
    return K-left+2;
}

Long computeSplitters(Long N,Long K)
{
    if(N==1)
        return 0;
    else if(K>=N)
        return 1;
    else if(sum(--K)<--N)
        return -1;
    return minSplitters(N,K);
}

int main()
{
    Long N, K;
    cin>>N>>K;

    cout<<computeSplitters(N,K)<<endl;
    return 0;
}

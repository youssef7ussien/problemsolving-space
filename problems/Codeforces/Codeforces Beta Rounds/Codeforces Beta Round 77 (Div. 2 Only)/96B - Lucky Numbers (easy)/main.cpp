#include <bits/stdc++.h>

using namespace std;
typedef long long Long;
#define MAX 1e11

Long result = MAX;
int N;

// counter: To check if 4's equal 7's is lucky or not.
Long superLuckyNumber(Long lucky=0,int counter=0)
{
    if(lucky>MAX)
        return result;

    if((lucky>=N && counter==0))
        result=min(result, lucky);

    superLuckyNumber(lucky*10+4, counter+1);
    superLuckyNumber(lucky*10+7, counter-1);
}

int main()
{
    cin>>N;

    superLuckyNumber();
    cout<<result<<"\n";

    return 0;
}

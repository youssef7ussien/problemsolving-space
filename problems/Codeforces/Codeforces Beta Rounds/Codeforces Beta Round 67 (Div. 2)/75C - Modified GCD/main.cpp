#include <bits/stdc++.h>

using namespace std;
#define SIZE(V) ((int)V.size())
#define BETWEEN(D,P) (D>=P.first && D<=P.second)

int GCD(int a,int b)
{
    if(b==0)
        return a;
    return GCD(b, a%b);
}

void generateDivisors(int N,vector<int> &divisors)
{
    int i=1;
    for(; i*i<N ; i++)
        if(N%i==0)
            divisors.push_back(i), divisors.push_back(N/i);

    if(i*i==N)
            divisors.push_back(i);
}

int binarySearch(const vector<int> &divisors,const pair<int,int> &query)
{
    int left=0, right=SIZE(divisors)-1;
    while(left<=right)
    {
        int middle=(left+right)/2;
        if(BETWEEN(divisors[middle],query) && (middle==SIZE(divisors)-1 || divisors[middle+1]>query.second))
            return divisors[middle];
        else if(BETWEEN(divisors[middle],query) || divisors[middle]<query.first)
            left=middle+1;
        else
            right=middle-1;
    }
    return -1;
}

void findGCDInRanges(int A,int B,vector<pair<int,int>> queries)
{
    vector<int> divisors;
    generateDivisors(GCD(A,B), divisors);
    sort(divisors.begin(), divisors.end());

    for(auto &it : queries)
        cout<<binarySearch(divisors, it)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int A,B,N;
    cin>>A>>B>>N;

    vector<pair<int,int>> queries(N);
    for(auto &it : queries)
        cin>>it.first>>it.second;

    findGCDInRanges(A,B,queries);
    return 0;
}

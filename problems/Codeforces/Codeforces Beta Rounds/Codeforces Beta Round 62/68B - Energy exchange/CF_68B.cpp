/**
 * Title: "Energy exchange", Codeforces problem. 
 * Date: Saturday, 12 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define EPS                         1e-9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


bool check(VI numbers, int K,double middle)
{
    double sumUp = 0, sumDown = 0;
    for(auto &it : numbers)
        it > middle ? sumDown += it - middle : sumUp += middle - it;
    
    return (sumDown * (100 - K) / 100 >= sumUp);
}

double binarySearch(VI numbers, int K)
{
    sort(ALL(numbers));

    double left = numbers.front(), right = numbers.back();
    while(right - left > EPS) {
        double middle = left + (right - left) / 2;

        check(numbers, K, middle) ? left = middle : right = middle;
    }

    return left;
}

int main()
{
    FAST_IO;
    
    int N, K;
    cin>>N>>K;
    VI numbers(N);

    for(auto &it : numbers)
        cin>>it;
    
    cout<<fixed<<setprecision(10)<<binarySearch(numbers, K)<<"\n";
    return 0;
}
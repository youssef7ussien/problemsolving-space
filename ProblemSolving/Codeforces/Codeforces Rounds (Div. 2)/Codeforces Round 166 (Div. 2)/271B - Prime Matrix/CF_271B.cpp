/**
 * Title: "Prime Matrix", Codeforces problem. 
 * Date: Thursday, 03 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e5+5

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


// with sieve algorithm O(n * log(log(n)))
void getAllPrime(set<int> &primes) 
{
    vector<bool> isPrime(INF+1, true);
    for(int i = 2 ; i * i <= INF ; i++) {
        if(isPrime[i])
            for(int j = i * i ; j <= INF ; j += i)
                isPrime[j] = false;
    }

    for(int i = 2 ; i < SIZE(isPrime) ; i++)
        if(isPrime[i])
            primes.insert(i);
}

int main()
{
    FAST_IO;

    set<int> primes;
    getAllPrime(primes);
    
    int N, M;
    cin>>N>>M;

    vector<VI> matrix(N, VI(M));
    for(auto &row : matrix)
        for(auto &it : row)
            cin>>it;
    
    VI sumRow(N), sumColumn(M);
    for(int i = 0 ; i<N ; i++)
        for(int j = 0 ; j<M ; j++) {
            sumRow[i] += matrix[i][j];
            sumColumn[j] += matrix[i][j];
        }
    
    for(int i = 0 ; i<N ; i++)
        for(int j = 0 ; j<M ; j++) {
            auto it = primes.lower_bound(matrix[i][j]);
            if(it != primes.end())
                matrix[i][j] = *it;
        }

    int result = INF;
    for(int i = 0 ; i<N ; i++) {
        int sum = 0;
        for(int j = 0 ; j<M ; j++)
            sum += matrix[i][j];
        result = min(result, sum - sumRow[i]);
    }

    for(int i = 0 ; i<M ; i++) {
        int sum = 0;
        for(int j = 0 ; j<N ; j++)
            sum += matrix[j][i];
        result = min(result, sum - sumColumn[i]);
    }

    cout<<result<<"\n";
    return 0;
}
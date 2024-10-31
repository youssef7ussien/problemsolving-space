/**
 * Title: "The Bits", Codeforces problem. 
 * Date: Thursday, 03 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


int main()
{
    FAST_IO;
    
    int N;
    string A, B;
    cin>>N>>A>>B;

    /**
     * @brief bitwise OR change if:
     * 1. [0 (in A) corresponds to 0 (in B)] swaped with [1 (in A) corresponds to 1 (in B)]
     * 2. [0 (in A) corresponds to 0 (in B)] swaped with [1 (in A) corresponds to 0 (in B)]
     * 3. [0 (in A) corresponds to 1 (in B)] swaped with [1 (in A) corresponds to 0 (in B)]
     * 
     * The answer = count(0-0) * count(1-1) + count(0-0) * count(1-0) + count(0-1) * count(1-0)
     */
    map<string, Long> counter;
    for(int i=0 ; i<N ; i++)
        counter[string(1, A[i]) + B[i]]++;
    
    cout<<(counter["00"] * counter["11"] + counter["00"] * counter["10"] + counter["01"] * counter["10"])<<"\n";
    return 0;
}
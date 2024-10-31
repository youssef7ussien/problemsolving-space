/**
 * Title: "Magic Powder - 2", Codeforces problem. 
 * Date: Wednesday, 16 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e10+2

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;


struct Ingredient {
    int exact, have;
};

bool check(const vector<Ingredient> &grams, int K, Long middle)
{
    for(auto &it : grams) {
        if(it.have >= it.exact * middle)
            continue;
        if(K < it.exact * middle - it.have)
            return false;
        K -= it.exact * middle - it.have;
    }

    return true;
}

Long binarySearch(const vector<Ingredient> &grams,int K)
{
    Long left = 0, right = INF;
    while(left < right) {
        Long middle = left + (right - left + 1) / 2;

        check(grams, K, middle) ?  left = middle : right = middle - 1;
    }

    return left;
}

int main()
{
    FAST_IO;

    int N, K;
    cin>>N>>K;

    vector<Ingredient> grams(N);
    for(auto &it : grams)
        cin>>it.exact;

    for(auto &it : grams)
        cin>>it.have;

    cout<<binarySearch(grams, K)<<"\n";
    return 0;
}
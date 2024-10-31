/**
 * Title: "New Years Problem", Codeforces problem. 
 * Date: Wednesday, 04 May 2022 
 * hint: Pigeonhole Principle (https://www.youtube.com/watch?v=YiZJEAdCsxA)
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     int(1e9+1)

typedef long long               Long;
typedef vector<int>             VI;
typedef vector<VI>              VVI;


bool check(const VVI &P, int middle)
{
    bool hasPair = false;
    vector<bool> friends(SIZE(P.front()));

    for(auto &it : P) {
        int counter = 0;
        for(int i = 0 ; i < SIZE(it) ; i++)
            counter += (it[i] >= middle), friends[i] = friends[i] || it[i] >= middle;

        hasPair = hasPair || counter >= 2;
    }

    return hasPair && all_of(ALL(friends), [](bool a) { return a; });
}

int binarySearch(const VVI &P)
{
    int left = 0, right = INF;
    while(left < right) {
        int middle = left + (right - left + 1) / 2;

        check(P, middle) ? left = middle : right = middle - 1;
    }

    return left;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int M, N;
        cin>>M>>N;

        VVI P(M, VI(N));
        for(auto &it1 : P)
            for(auto &it2 : it1)
                cin>>it2;

        cout<<binarySearch(P)<<"\n";
    }
    
    return 0;
}
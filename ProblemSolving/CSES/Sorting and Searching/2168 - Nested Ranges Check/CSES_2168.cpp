/**
 * Title: "Nested Ranges Check", CSES problem. 
 * Date: Monday, 14 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9+5

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;


struct Range {
    int left, right, index;

    bool operator <(const Range range){
        return left == range.left ? right > range.right : left < range.left;
    } 
};

void print(const VI &result) {
    for(auto &it : result) 
        cout<<it<<" "; 
    cout<<"\n";
}

int main()
{
    FAST_IO;
    
    int N;
    cin>>N;

    vector<Range> ranges(N);
    VI itContains(N), containsIt(N);
    for(int i = 0 ; i<N ; i++) {
        cin>>ranges[i].left>>ranges[i].right;
        ranges[i].index = i;
    }

    sort(ALL(ranges));
    
    int minRight = INF, maxRight = -INF;

    for(int i = N - 1 ; i >= 0 ; i--) {
        itContains[ranges[i].index] = (ranges[i].right >= minRight);
        minRight = min(minRight, ranges[i].right);
    }

    for(int i = 0 ; i < N ; i++) {
        containsIt[ranges[i].index] = (ranges[i].right <= maxRight);
        maxRight = max(maxRight, ranges[i].right);
    }

    print(itContains), print(containsIt);
    
    return 0;
}
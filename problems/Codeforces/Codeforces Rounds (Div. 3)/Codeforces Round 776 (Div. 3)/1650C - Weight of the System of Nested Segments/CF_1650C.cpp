/**
 * Title: "Weight of the System of Nested Segments", Codeforces problem. 
 * Date: Tuesday, 08 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;


struct Point {
    int X, W, index;

    // sort based on position
    bool operator <(const Point &point) {
        return X == point.X ? W < point.W : X < point.X;
    }
};

void print(const vector<Point> &result)
{
    int sum = 0;
    for(int i = 0 ; i < SIZE(result) ; i++)
        sum += result[i].W;

    cout<<sum<<"\n";
    for(int i = 0, j = SIZE(result)-1 ; i < j ; i++, j--)
        cout<<result[i].index<<" "<<result[j].index<<"\n";
}

void solve(vector<Point> points,int N) 
{
    // sort based on small weight
    sort(ALL(points), [](const Point &a, const Point &b) {
        return a.W == b.W ? a.X < b.X : a.W < b.W;
    });

    vector<Point> smallPoints(points.begin(), points.begin() + 2*N);
    
    sort(ALL(smallPoints));

    print(smallPoints);
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        string line;
        int N, M;
        cin>>N>>M;

        vector<Point> points(M);
        for(int i = 0 ; i < M ; i++) {
            cin>>points[i].X>>points[i].W;
            points[i].index = i + 1;
        }

        solve(points, N);
        cout<<(T == 0 ? "" : "\n");
    }
    
    return 0;
}
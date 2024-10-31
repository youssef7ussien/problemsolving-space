/**
 * Title: "Balls Game", Codeforces problem. 
 * Date: Wednesday, 23 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define SIZE(v)                     ((int)((v).size()))
#define CIN_TEMP(T)                 int T; cin>>T;
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                         1e9

typedef long long                   Long;
typedef pair<int, int>              PII;
typedef vector<int>                 VI;
typedef vector<PII>                 VII;


int countBalls(const VII &balls, int index) 
{
    int left = index - 1, right = index + 1, counter = balls[index].second;
    while(left >= 0 && right < SIZE(balls)) {
        if(balls[left].first == balls[right].first && balls[left].second + balls[right].second >= 3)
            counter += balls[left].second + balls[right].second;
        else
            break;
        
        left--, right++;
    }

    return counter;
}

int main()
{
    FAST_IO;
    
    int N, K, X;
    cin>>N>>K>>X;

    VII balls;
    for(int i = 0 ; i < N ; i++) {
        CIN_TEMP(temp);
        if(i != 0 && balls.back().first == temp)
            balls.back().second++;
        else
            balls.push_back({temp, 1});
    }

    int result = 0;
    for(int i = 0 ; i < N ; i++)
        if(balls[i].first == X && balls[i].second == 2)
            result = max(result, countBalls(balls, i));
    
    cout<<result<<"\n";
    return 0;
}
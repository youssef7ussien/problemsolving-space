/**
 * Title: "Required Length", Codeforces problem. 
 * Date: Tuesday, 24 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<Long>            VL;
typedef vector<PII>             VII;


int BFS(int N, Long X)
{
    if(N == LEN(to_string(X)))
        return 0;
    
    int counter = 0;
    map <Long, bool> visited;
    queue <Long> queueBFS;
    queueBFS.push(X);

    while(!queueBFS.empty()) {
        int queueSize = LEN(queueBFS);
        counter++;
        
        while(queueSize--) {
            Long num = queueBFS.front();
            queueBFS.pop();
            string numStr = to_string(num);
            
            sort(R_ALL(numStr));

            for(auto &it : numStr) {
                if(it < '2')
                    break;
                Long value = (it - '0') * num;
                if(LEN(to_string(value)) == N)
                    return counter;
                else if(!visited[value])
                    queueBFS.push(value), visited[value] = true;
            }
        }
    }

    return -1;
}

int main()
{
    FAST_IO;
    
    int N;
    Long X;
    cin>>N>>X;

    cout<<BFS(N, X)<<"\n";
    return 0;
} 
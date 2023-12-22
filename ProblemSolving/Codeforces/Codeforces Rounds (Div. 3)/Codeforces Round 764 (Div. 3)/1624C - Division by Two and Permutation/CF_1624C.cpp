/**
 * Title: "Division by Two and Permutation", Codeforces problem. 
 * Date: Friday, 29 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        vector<bool> visited(N + 1);
        queue<int> waiting;
        int counter = 0;
        
        for(int i = 0 ; i < N ; i++) {
            CIN(temp);
            if(temp <= N && !visited[temp])
                visited[temp] = true, counter++;
            else
                waiting.push(temp);
        }
        
        while(!waiting.empty()) {
            int number = waiting.front();
            waiting.pop();

            while(number > N || visited[number])
                number /= 2;

            if(number > 0)
                visited[number] = true, counter++;
        }

        cout<<(counter == N ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Vertical Paths", Codeforces problem. 
 * Date: Friday, 06 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


void print(const deque<int> &result) {
    cout<<SIZE(result)<<"\n";
    for(auto &it : result)
        cout<<it<<" ";
    cout<<"\n";
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
                
        VI parent(N + 1), leaves;
        vector<bool> visited(N + 1), freq(N + 1);
        
        for(int i = 1 ; i <= N ; i++) {
            CIN(temp);
            parent[i] = temp, freq[temp] = true;
        }

        for(int i = 1 ; i <= N ; i++)
            if(!freq[i])
                leaves.push_back(i);
        
        if(SIZE(leaves))
            cout<<SIZE(leaves)<<"\n";
        else 
            cout<<"1\n1\n1\n";

        for(auto &leave : leaves) {
            deque<int> result;

            result.push_front(leave);
            
            int current = parent[leave];
            while(!visited[current]) {
                result.push_front(current);
                visited[current] = true, current = parent[current];
            }

            print(result);
        }

        cout<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Team Queue", UVA Online Judge problem. 
 * Date: Sunday, 19 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)     freopen(file, "r", stdin)
#define FILE_OUT(file)    freopen(file, "w", stdout)

typedef long long         Long;


int searchIndex(deque<queue<int>> &teamsQueue,map<int, int> &teams,int member) {
    for (auto &it : teamsQueue)
        if(teams[it.front()] == teams[member])
        {
            it.push(member);
            return true;
        }
        
    return false;
}

int main()
{
    #ifdef DEBUG
        FILE_IN("__UVA_540_input.txt");
        FILE_OUT("__UVA_540_output.txt");
    #endif
    
    FAST_IO;

    int T;
    int counter = 1;
    while(cin>>T, T != 0)
    {
        map<int, int> teams;
        deque<queue<int>> teamsQueue;

        for(int i=0 ; i<T ; i++) {
            int N;
            cin>>N;
            while(N--) {
                int temp; cin>>temp;
                teams[temp] = i;
            }
        }

        cout<<"Scenario #"<<counter++<<"\n";

        string command;
        while(cin>>command, command[0] != 'S')
        {
            if(command[0] == 'E') {
                int member;
                cin>>member;

                if(!searchIndex(teamsQueue,teams, member))
                    teamsQueue.push_back(queue<int>({member}));
            }
            else {
                cout<<teamsQueue.front().front()<<"\n";
                teamsQueue.front().pop();

                if(teamsQueue.front().empty())
                    teamsQueue.pop_front();
            }
        }
        cout<<"\n";
    }
    
    return 0;
}
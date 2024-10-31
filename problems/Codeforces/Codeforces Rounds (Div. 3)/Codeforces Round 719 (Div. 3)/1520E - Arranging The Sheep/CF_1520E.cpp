/**
 * Title: "Arranging The Sheep", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        VI sheeps;
        for(int i = 0 ; i < N ; i++) {
            char ch;
            cin>>ch;
            if(ch == '*')
                sheeps.push_back(i);
        }
        
        Long counter = 0;
        for(int i = 0 ; i < SIZE(sheeps) ; i++)
            counter += abs(sheeps[i] - sheeps[SIZE(sheeps) / 2]) - abs(SIZE(sheeps) / 2 - i);
        
        cout<<counter<<"\n";
    }
    
    return 0;
}
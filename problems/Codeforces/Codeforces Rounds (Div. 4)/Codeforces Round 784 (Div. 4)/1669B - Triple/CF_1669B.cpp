/**
 * Title: "Triple", Codeforces problem. 
 * Date: Thursday, 21 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<PII>             VII;


int main()
{   
    FAST_IO;
    
    TEST_CASES(T) {
        int counter = -1, N;
        cin>>N;
        
        map<int,int> freq;
        for(int i=0 ; i<N ; i++) {
            int temp;
            cin>>temp;
            freq[temp]++;
            
            if(freq[temp] >= 3)
               counter = temp;
        }

        cout<<counter<<"\n";
    }
    
    return 0;
}
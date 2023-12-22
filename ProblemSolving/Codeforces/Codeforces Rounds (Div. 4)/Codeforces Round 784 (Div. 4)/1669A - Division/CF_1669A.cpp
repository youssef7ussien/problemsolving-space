/**
 * Title: "Division", Codeforces problem. 
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
        int N;
        cin>>N;

        if(N >= 1900)
            cout<<"Division 1"<<"\n";
        else if(N >= 1600 && N <= 1899)
            cout<<"Division 2"<<"\n";
        else if(N >= 1400 && N <= 1599)
            cout<<"Division 3"<<"\n";
        else if(N <= 1399)
            cout<<"Division 4"<<"\n";

    }
    
    return 0;
}
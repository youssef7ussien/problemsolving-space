/**
 * Title: "Throwing cards away I", UVA Online Judge problem. 
 * Date: Saturday, 18 December 2021 
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
#define MP                make_pair
#define PB                push_back
#define FF                first
#define SS                second
#define INF               1e9

typedef long long         Long;
typedef pair<int, int>    PII;
typedef vector<int>       VI;
typedef vector<PII>       VII;

int main()
{
    #ifdef DEBUG
        FILE_IN("__UVA_10935_input.txt");
        FILE_OUT("__UVA_10935_output.txt");
    #endif
    
    FAST_IO;

    int N;
    while((cin>>N) && N!=0) {
        queue<int> cards;
        VI discards;

        for(int i=1 ; i<=N ; i++)
            cards.push(i);
        
        while(SIZE(cards) > 1) {
            discards.PB(cards.front());
            cards.pop();

            cards.push(cards.front());
            cards.pop();
        }
        
        cout<<"Discarded cards:";
        for(int i=0 ; i<SIZE(discards) ; i++)
            cout<<(i == 0 ? " " : "")<<discards[i]<<(i == SIZE(discards)-1 ? "" : ", ");
        cout<<"\nRemaining card: "<<cards.front()<<"\n";

    }
    
    return 0;
}
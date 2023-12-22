/**
 * Title: "Pole Position", UVA Online Judge problem. 
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
#define INF               1e9

typedef long long         Long;
typedef pair<int, int>    PII;
typedef vector<int>       VI;

int main()
{
    #ifdef DEBUG
        FILE_IN("__UVA_12150_input.txt");
        FILE_OUT("__UVA_12150_output.txt");
    #endif
    
    FAST_IO;
    
    int N;
    while((cin>>N) && N!=0)
    {
        VI pole(N, -1);
        bool valid = true;

        for(int i=0 ; i<N ; i++)
        {
            int num, v;
            cin>>num>>v;
            if(i + v > N || i + v < 0)
                valid = false;
            else 
                pole[i + v] != -1 ? valid = false : pole[i + v] = num;
        }

        if(!valid)
            cout<<"-1"<<"\n";
        else
        {
            for(int i=0 ; i<SIZE(pole) ; i++)
                cout<<pole[i]<<(i == SIZE(pole)-1 ? "" : " ");
            cout<<"\n";
        }
    }
    
    return 0;
}
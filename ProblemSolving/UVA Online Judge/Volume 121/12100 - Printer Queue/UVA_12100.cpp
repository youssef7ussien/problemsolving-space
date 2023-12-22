/**
 * Title: "Printer Queue", UVA Online Judge problem. 
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
        FILE_IN("__UVA_12100_input.txt");
        FILE_OUT("__UVA_12100_output.txt");
    #endif
    
    FAST_IO;
    
    TEST_CASES(T) {
        int N, M;
        cin>>N>>M;

        queue<pair<int, int>> printer;
        priority_queue<pair<int, int>> priorityPrinter;
        for(int i=0 ; i<N ; i++) {
            int temp;
            cin>>temp;
            printer.push({temp, i});
            priorityPrinter.push({temp, i});
        }

        int counter = 0;
        while(true)
        {
            if(printer.front().first == priorityPrinter.top().first)
            {
                counter++;
                priorityPrinter.pop();
                if(printer.front().second == M)
                    break;
            }
            else
                printer.push(printer.front());
            printer.pop();
        }
        
        cout<<counter<<"\n";
    }

    
    return 0;
}
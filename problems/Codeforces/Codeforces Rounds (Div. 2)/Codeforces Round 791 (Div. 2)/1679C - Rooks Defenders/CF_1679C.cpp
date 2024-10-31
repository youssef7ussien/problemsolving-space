/**
 * Title: "Rooks Defenders", Codeforces problem. 
 * Date: Saturday, 14 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    int N, Q;
    cin>>N>>Q;
    
    map<int, int> freqRow, freqCol;
    set<int> rows, columns; // Rows and columns that do not have a rock.
    for(int i = 1 ; i <= N + 1 ; i++)
        rows.insert(i), columns.insert(i);
        
    while(Q--) {
        int type;
        cin>>type;

        if(type == 1 || type == 2) {
            int num1, num2;
            cin>>num1>>num2;
            
            if(type == 1) {
                if(!freqRow[num1])  rows.erase(num1);
                if(!freqCol[num2])  columns.erase(num2);
                
                freqRow[num1]++, freqCol[num2]++;
            }
            else {
                freqRow[num1]--, freqCol[num2]--;

                if(!freqRow[num1])  rows.insert(num1);
                if(!freqCol[num2])  columns.insert(num2);
            }
        }
        else {
            int x1, y1, x2, y2;
            cin>>x1>>y1>>x2>>y2;

            cout<<(*rows.lower_bound(x1) > x2 || *columns.lower_bound(y1) > y2 ? "Yes" : "No")<<"\n";
        }
    }
    
    return 0;
}
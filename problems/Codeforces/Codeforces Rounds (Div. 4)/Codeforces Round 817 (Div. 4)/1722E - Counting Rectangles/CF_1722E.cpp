/**
 * Title: "Counting Rectangles", Codeforces problem. 
 * Date: Wednesday, 31 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<Long>            VL;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, Q;
        cin>>N>>Q;

        vector<VL> prefix(1002, VL(1002));
        for(int i = 0 ; i < N ; i++) {
            int h, w; 
            cin>>h>>w;

            prefix[h][w] += h * w;
        }

        for(int i = 1 ; i <= 1001 ; i++)
            for(int j = 0 ; j <= 1001 ; j++)
                prefix[i][j] += prefix[i - 1][j];

        for(int i = 0 ; i <= 1001 ; i++)
            for(int j = 1 ; j <= 1001 ; j++)
                prefix[i][j] += prefix[i][j - 1];

        while(Q--) {
            int h1, w1, h2, w2;
            cin>>h1>>w1>>h2>>w2;
            
            h1++,w1++, h2--,w2--;
            
            cout<<prefix[h2][w2] - prefix[h1 - 1][w2] - prefix[h2][w1 - 1] + prefix[h1 - 1][w1 - 1]<<"\n";
        }
    }
    
    return 0;
}
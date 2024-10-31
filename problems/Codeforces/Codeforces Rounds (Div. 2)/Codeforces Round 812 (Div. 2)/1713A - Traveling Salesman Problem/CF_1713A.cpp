/**
 * Title: "Traveling Salesman Problem", Codeforces problem. 
 * Date: Sunday, 07 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        pair<int, int> X = {0, 0}, Y = {0, 0};
        while(N--) {
            pair<int, int> p;
            cin>>p.FF>>p.SS;

            X = {max(p.FF, X.FF), min(p.FF, X.SS)};
            Y = {max(p.SS, Y.FF), min(p.SS, Y.SS)};
        }

        cout<<(X.FF + abs(X.SS) + Y.FF + abs(Y.SS)) * 2<<"\n";
    }
    
    return 0;
}
/**
 * Title: "A-B Matrix", Codeforces problem. 
 * Date: Wednesday, 11 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, M, A, B;
        cin>>N>>M>>A>>B;

        if(N * A != M * B) {
            cout<<"NO\n";
            continue;
        }

        int column = 0;
        vector<vector<char>> matrix(N, vector<char>(M, '0'));
        
        for(auto &it : matrix)
            for(int i = 0 ; i < A ; i++) {
                if(column >= M)
                    column = 0;
                it[column++] = '1';
            }


        cout<<"YES\n";
        for(auto &it1 : matrix) {
            for(auto &it2 : it1)
                cout<<it2;
            cout<<"\n";
        }
    }
    
    return 0;
}
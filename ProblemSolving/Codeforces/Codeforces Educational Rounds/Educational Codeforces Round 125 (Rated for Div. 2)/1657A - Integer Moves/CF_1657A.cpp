/**
 * Title: "Integer Moves", Codeforces problem. 
 * Date: Friday, 25 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)       int T; cin>>T; while(T--)
#define FAST_IO             ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;

    TEST_CASES(T) {
        int x, y;
        cin>>x>>y;

        if(x + y == 0){
            cout<<"0"<<"\n";
            continue;
        }
        
        double z = sqrt(x * x + y * y);
        cout<<(z == (int)z ? 1 : 2)<<"\n";
    }
    
    return 0;
}
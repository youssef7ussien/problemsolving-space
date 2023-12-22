/**
 * Title: "Add Modulo 10", Codeforces problem. 
 * Date: Monday, 01 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI arr(N);
        int count5 = 0;
        for(auto &it : arr) {
            cin>>it;

            if(it % 2 == 1)
                it += it % 10;
            count5 += (it % 5 == 0);
        }
        
        sort(ALL(arr));

        if(count5 > 0)
            { cout<<(arr[0] == arr.back() ? "YES" : "NO")<<"\n"; continue; }
        
        bool can = true;
        for(int i = 0 ; i < N ; i++) {
            while(arr[i] % 10 != 2)
                arr[i] += arr[i] % 10;

            if(i != 0 && arr[i] % 20 != arr[0] % 20)
                { can = false; break; }
        }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}
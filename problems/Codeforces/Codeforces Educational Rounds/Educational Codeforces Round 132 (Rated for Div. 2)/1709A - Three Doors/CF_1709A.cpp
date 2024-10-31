/**
 * Title: "Three Doors", Codeforces problem. 
 * Date: Wednesday, 03 August 2022 
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
        int N;
        cin>>N;

        int arr[4];
        cin>>arr[1]>>arr[2]>>arr[3];
        
        cout<<(arr[N] != 0 && arr[arr[N]] != 0 ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}
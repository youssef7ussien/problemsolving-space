/**
 * Title: "Build Permutation", Codeforces problem. 
 * Date: Sunday, 07 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

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
        for(int i = N - 1, num = 0 ; i >= 0 ; i = num - 1) {
            // With any positive integer x, there is at least one square number in [x,2x]
            // pow(ceil(sqrt(x)), 2) ==> square number in [x , 2x]
            num = pow(ceil(sqrt(i)), 2) - i;

            for(int j = num, k = i ; j <= i ; j++)
                arr[j] = k--;
        }

        for(auto &it : arr)
          cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Mystic Permutation", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI arrA(N), arrB(N);
        for(int i = 0 ; i < N ; i++) {
            cin>>arrA[i];
            arrB[i] = i + 1;
        }

        if(N == 1) 
            { cout<<"-1\n"; continue; }

        for(int i = 0 ; i < N - 1 ; i++)
            if(arrA[i] == arrB[i])
                swap(arrB[i], arrB[i + 1]);
        
        if(arrA[N - 1] == arrB[N - 1])
                swap(arrB[N - 2], arrB[N - 1]);

        for(auto &it : arrB)
          cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}
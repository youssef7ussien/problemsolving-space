/**
 * Title: "A-B-C Sort", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
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
        VI numbers(N);
        for(auto &it : numbers)
            cin>>it;
        
        for(int i = (N % 2 == 0 ? 0 : 1) ; i < N - 1 ; i += 2)
            if(numbers[i] > numbers[i + 1])
                swap(numbers[i], numbers[i + 1]);

        bool can = true;
        for(int i = 0 ; i < N - 1 ; i++)
            if(numbers[i] > numbers[i + 1])
                { can = false; break; }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}
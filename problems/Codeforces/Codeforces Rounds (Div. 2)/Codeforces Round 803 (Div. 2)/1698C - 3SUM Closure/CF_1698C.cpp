/**
 * Title: "3SUM Closure", Codeforces problem. 
 * Date: Tuesday, 28 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        bool zero = false;
        int countPos = 0, countNeg = 0;
        map<Long, Long> freq;
        VI arr;
        
        for(int i = 0 ; i < N ; i++) {
            CIN(num);
            freq[num]++;

            if(num != 0)
                arr.push_back(num), (num < 0 ? countNeg++ : countPos++);
            else
                zero = true;
        }

        if(countPos > 2 || countNeg > 2)
            { cout<<"NO\n"; continue; }
        
        if(zero)
            arr.push_back(0);

        bool can = true;
        for (int i = 0 ; i < LEN(arr) ; i++)
            for (int j = i + 1 ; j < LEN(arr) ; j++)
                for (int k = j + 1 ; k < LEN(arr) ; k++)
                    if(freq[arr[i] + arr[j] + arr[k]] == 0)
                        can = false;
                        
        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Double Sort", Codeforces problem. 
 * Date: Monday, 23 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<Long>            VL;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        VI arr1(N), arr2(N), arr3(N), arr4(N);

        for (int i = 0; i < N; i++) {
            cin>>arr1[i];
            arr3[i] = arr1[i];
        }
        
        for (int i = 0; i < N; i++) {
            cin>>arr2[i];
            arr4[i] = arr2[i];
        }

        sort(ALL(arr3)), sort(ALL(arr4));

        int counter = 0;
        map<int, int> freq;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                if (arr3[i] == arr1[j] && arr4[i] == arr2[j] && !freq[j])
                    freq[j] = 1, counter++;
        }

        if (counter != N)
            cout<<"-1\n";
        else
        {
            VII result;
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    if (arr3[i] == arr1[j] && arr4[i] == arr2[j]) {
                        swap(arr1[j], arr1[i]), swap(arr2[j], arr2[i]);
                        result.push_back({j, i});
                    }
                }
            }

            if(LEN(result) > 10000)
                cout<<"-1\n";
            else {
                cout<<LEN(result)<<"\n";
                for(auto &it : result)
                    cout<<it.FF + 1<<" "<<it.SS + 1<<"\n";
            }
        }
    }
    
    return 0;
}
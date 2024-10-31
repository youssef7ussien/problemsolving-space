/**
 * Title: "Line", Codeforces problem. 
 * Date: Tuesday, 30 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;
typedef vector<Long>            VL;

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        string str;
        cin>>N>>str;

        VI arr(N);
        VL result(N);
        Long sum = 0;

        for(int i = 0 ; i < N ; i++)
            arr[i] = (str[i] == 'L' ? i : N - i - 1), sum += arr[i];

        int left = 0, right = N - 1, maxL = N / 2, maxR = N / 2 - (N % 2 == 0);
        for(int k = 0 ; k < N ; k++) {
            while(left < maxL && str[left] == 'R')  left++;
            while(right > maxR && str[right] == 'L') right--;
            
            if(left < maxL && (N - left - 1) >= right)
                sum += (N - left - 1) - arr[left], left++;
            else if(right > maxR && (N - left - 1) <= right)
                sum += right - arr[right], right--;
            
            result[k] = sum;
        }

        for(auto &it : result)
          cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}
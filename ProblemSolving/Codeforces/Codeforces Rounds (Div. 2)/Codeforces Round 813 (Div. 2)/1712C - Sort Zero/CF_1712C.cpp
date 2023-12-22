/**
 * Title: "Sort Zero", Codeforces problem. 
 * Date: Saturday, 13 August 2022 
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
        for(auto &it : arr)
            cin>>it;

        vector<bool> removed(N + 1);
        for(int left = 0, right = 1 ; right < N ; right++) {
            if(removed[arr[right]])
                arr[right] = 0;

            if(arr[right - 1] > arr[right])
                while(left < right)
                    removed[arr[left]] = true, arr[left++] = 0;
        }

        cout<<count(removed.begin() + 1, removed.end(), true)<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Alice, Bob and Candies", Codeforces problem. 
 * Date: Thursday, 21 April 2022 
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
        VI numbers(N);
        for(auto &it : numbers)
            cin>>it;
        
        int left = 0, right = N - 1, last = 0, countA = 0, countB = 0, counter = 0;
        while(left <= right) {
            if(counter % 2 == 0) {
                int temp = numbers[left++];
                while(temp <= last && left <= right)
                    temp += numbers[left++];
                counter++, countA += temp, last = temp;
            } 
            else {
                int temp = numbers[right--];
                while(temp <= last && left <= right)
                    temp += numbers[right--];
                counter++, countB += temp, last = temp;
            }
        }

        cout<<counter<<" "<<countA<<" "<<countB<<"\n";
    }
    
    return 0;
}
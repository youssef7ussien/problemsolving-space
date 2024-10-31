/**
 * Title: "Sum of Three Values", CSES problem. 
 * Date: Thursday, 17 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define R_ALL(v)                    ((v).rbegin()), ((v).rend())
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                          first
#define SS                          second


int main()
{
    FAST_IO;
    
    int N, sum;
    cin>>N>>sum;

    vector<pair<int, int>> numbers(N);
    for(int i = 0 ; i < N ; i++) {
        cin>>numbers[i].first;
        numbers[i].second = i + 1;
    }

    sort(ALL(numbers));
    
    for(int i = 0 ; i < N - 2 ; i++) {
        int left = i + 1, right = N - 1;
        while(left < right) {
            if(numbers[i].FF + numbers[left].FF + numbers[right].FF > sum)
                right--;
            else if(numbers[i].FF + numbers[left].FF + numbers[right].FF < sum)
                left++;
            else { 
                cout<<numbers[i].SS<<" "<<numbers[left].SS<<" "<<numbers[right].SS<<"\n";
                return 0;
            }
        }
    }

    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}
/**
 * Title: "Studying Algorithms", Codeforces GYM problem.
 * Date: Friday, 19 August 2022
 * Contest: USACO Guide Problem Submission (https://codeforces.com/gym/102951)
 * 
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    int N, X;
    cin>>N>>X;
    
    VI arr(N);
    for(auto &it : arr)
        cin>>it;
    
    sort(ALL(arr));
    
    int counter = 0;
    for(int i = 0, sum = 0 ; i < N ; i++)
        sum += arr[i], counter += (sum <= X);

    cout<<counter<<"\n";
    
    return 0;
}

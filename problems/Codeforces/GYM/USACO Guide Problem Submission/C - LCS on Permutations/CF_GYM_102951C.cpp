/**
 * Title: "LCS on Permutations", Codeforces GYM problem.
 * Date: Friday, 19 August 2022
 * Contest: USACO Guide Problem Submission (https://codeforces.com/gym/102951)
 * hint: https://stackoverflow.com/a/30769175/13377098
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
    
    int N;
    cin>>N;
    
    VI arr1(N), arr2(N), arr3(N);
    map<int, int> pos;

    for(int i = 0 ; i < N ; i++) { 
        cin>>arr1[i];
        pos[arr1[i]] = i;
    }

    for(auto &it : arr2) cin>>it;

    for(int i = 0 ; i < N ; i++)
        arr3[i] = pos[arr2[i]];

    VI result;
    for(auto &curr : arr3) {
        auto it = lower_bound(ALL(result), curr);
        if(it == result.end())
            result.push_back(curr);
        else
            *it = curr;
    }

    cout<<result.size()<<"\n";
    return 0;
}

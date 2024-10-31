/**
 * Title: "Maximum Distance", Codeforces GYM problem.
 * Date: Friday, 19 August 2022
 * Contest: USACO Guide Problem Submission (https://codeforces.com/gym/102951)
 * 
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    VI arrX(N), arrY(N);
    for(auto &it : arrX) cin>>it;

    for(auto &it : arrY) cin>>it;

    Long result = 0;
    for(int i = 0 ; i < N ; i++)
    for(int j = i + 1 ; j < N ; j++)
        result = max(result, Long(pow(arrX[i] - arrX[j], 2) + pow(arrY[i] - arrY[j], 2)));

    cout<<result<<"\n";
    return 0;
}

/**
 * Title: "Minimum Triangulation", Codeforces problem. 
 * Date: Monday, 08 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    int N;
    cin>>N;

    int result = 0;
    for(int i = 3 ; i <= N ; i++)
        result += i * (i - 1);

    cout<<result<<"\n";
    return 0;
}
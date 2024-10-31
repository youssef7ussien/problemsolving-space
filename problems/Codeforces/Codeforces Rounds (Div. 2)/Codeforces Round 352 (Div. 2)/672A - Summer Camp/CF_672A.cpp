/**
 * Title: "Summer Camp", Codeforces problem. 
 * Date: Friday, 24 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    string str;
    for(int i = 1 ; i < 1000 ; i++)
        str += to_string(i);
    
    int N;
    cin>>N;
    
    cout<<str[N - 1]<<"\n";
    return 0;
}
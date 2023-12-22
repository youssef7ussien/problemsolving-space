/**
 * Title: "Divisibility", Codeforces problem. 
 * Date: Monday, 22 August 2022 
 * hint: https://stackoverflow.com/a/11805119/13377098
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;

int main()
{
    FAST_IO;
    
    Long k, a, b;
    cin>>k>>a>>b;

    a = (a <= 0 ? a / k - 1 : (a - 1) / k);
    b = (b < 0 ? (b + 1) / k - 1 : b / k);
    
    cout<<b - a<<"\n";
    
    return 0;
}
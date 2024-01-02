/**
 * Title: "Weird Algorithm", CSES problem. 
 * Date: Thursday, 02 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;


int main()
{
    FAST_IO;
    
    Long N;
    cin>>N;
    while(N != 1) {
         cout<<N<<" ";
         N = N % 2 == 0 ? N / 2 : N * 3 + 1;
    }
    cout<<N<<"\n";
    return 0;
}
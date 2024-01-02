/**
 * Title: "Permutations", CSES problem. 
 * Date: Thursday, 02 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    if(N == 1)
        cout<<"1\n";
    else if(N <= 3)
        cout<<"NO SOLUTION\n";
    else {   
        for(int i = N - N % 2  ; i > 4 ; i -= 2)
            cout<<i<<" ";
        cout<<"2 4 ";
        for(int i = 1 ; i <= N ; i += 2)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
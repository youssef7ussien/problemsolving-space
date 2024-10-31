/**
 * Title: "Increasing Array", CSES problem. 
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
    
    int N;
    cin>>N;
    
    Long result = 0;
    for(int i = 0, prev = 0 ; i < N ; i++) {
        int num; cin>>num;

        if(i != 0 && prev - num > 0)
            result += prev - num;
        else
            prev = num;
    }
    
    cout<<result<<"\n";
    return 0;
}
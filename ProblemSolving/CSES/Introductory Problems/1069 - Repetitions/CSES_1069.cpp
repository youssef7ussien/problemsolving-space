/**
 * Title: "Repetitions", CSES problem. 
 * Date: Thursday, 02 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    string str;
    cin>>str;

    int counter = 1, temp = 1;
    for(int i = 1 ; i < LEN(str) ; i++)
        if(str[i] == str[i - 1])
            temp++;
        else
            counter = max(counter, temp), temp = 1;
    
    cout<<max(counter, temp)<<"\n";
    return 0;
}
/**
 * Title: "Joysticks", Codeforces problem. 
 * Date: Tuesday, 09 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

int main()
{
    FAST_IO;
    
    int a1, a2;
    cin>>a1>>a2;

    if(a1 + a2 == 2)
        { cout<<"0\n"; return 0; }
    
    int counter = 0;
    while(a1 > 0 && a2 > 0) {
        if(a1 > a2)
            a1 -= 2, a2++;
        else
            a1++, a2 -= 2;
            
        counter++;
    }
        
    cout<<counter<<"\n";
    return 0;
}
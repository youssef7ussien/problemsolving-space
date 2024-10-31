/**
 * Title: "Restoring the Duration of Tasks", Codeforces problem. 
 * Date: Friday, 10 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI arrS(N), arrF(N), arrD(N);
        for(auto &it : arrS)
            cin>>it;
        for(auto &it : arrF)
            cin>>it;
        
        arrD[0] = arrF[0] - arrS[0];
        for(int i = 1 ; i < N ; i++)
            arrD[i] = (arrS[i] >= arrF[i - 1] ? arrF[i] - arrS[i] :  arrF[i] - arrF[i - 1]);
        
        for(auto &it : arrD)
          cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}
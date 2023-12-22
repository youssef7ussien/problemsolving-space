/**
 * Title: "Meme Problem", Codeforces problem. 
 * Date: Wednesday, 06 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        double d;
        cin>>d;
        
        if(d == 0)
            cout<<"Y "<<fixed<<setprecision(10)<<0.0<<" "<<setprecision(10)<<0.0<<"\n";
        else if(d <= 3)
            cout<<"N\n";
        else {
            double b = (d + sqrt(d * d - 4 * d)) / 2.0;
            cout<<"Y "<<fixed<<setprecision(10)<<d - b<<" "<<setprecision(10)<<b<<"\n";
        }
    }

    return 0;
}
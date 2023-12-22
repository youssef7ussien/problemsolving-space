/**
 * Title: "Guess the K-th Zero (Easy version)", Codeforces problem. 
 * Date: Tuesday, 03 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;


int main()
{   
    FAST_IO;
    
    int N, T, K;
    cin>>N>>T>>K;

    int left = 1, right = N;
    while(left < right) {
        int middle = left + (right - left) / 2;
        
        cout<<"? "<<left<<" "<<middle<<"\n";
        cout.flush();

        int query;
        cin>>query;

        query = (middle - left + 1) - query;
        if(query < K)
            left = middle + 1, K -= query;
        else
            right = middle;

    }

    cout<<"! "<<left<<"\n";
	cout.flush();
    
    return 0;
}
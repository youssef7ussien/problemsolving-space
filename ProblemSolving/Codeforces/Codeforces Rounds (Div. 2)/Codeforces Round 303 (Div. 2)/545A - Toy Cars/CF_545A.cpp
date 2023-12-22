/**
 * Title: "Toy Cars", Codeforces problem. 
 * Date: Sunday, 08 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;

    int counter = N;
    vector<bool> result(N);
    for(int i = 0 ; i < N; i++)
        result[i] = true;

    for(int i = 0 ; i < N; i++)
        for(int j = 0 ; j < N ; j++) {
            CIN(num);

            if((num == 1 || num == 3) && result[i])
                result[i] = false, counter--;
            else if(num == 2 && result[j])
                result[j] = false, counter--;
        }
    
    cout<<counter<<"\n";
    for(int i = 0 ; i < N ; i++)
      if(result[i])
        cout<<i + 1<<" ";
    cout<<"\n";

    return 0;
}
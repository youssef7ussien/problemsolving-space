/**
 * Title: "Number of Smaller", Uncategorized problem. 
 * Date: Friday, 08 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;

int main()
{
    FAST_IO;
    
    int N, M;
    cin>>N>>M;
    
    VI arrA(N), arrB(M);
    for(auto &it : arrA)
        cin>>it;

    for(auto &it : arrB)
        cin>>it;

    for(int i = 0, j = 0, cnt = 0; j < LEN(arrB) ; j++) {
        while(i < LEN(arrA) && arrA[i] < arrB[j])
            cnt++, i++;

        cout<<cnt<<" ";
    }
    
    cout<<"\n";
    return 0;
}
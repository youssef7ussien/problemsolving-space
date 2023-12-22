/**
 * Title: "Merging Arrays", Uncategorized problem. 
 * Date: Friday, 08 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
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

    int i = 0, j = 0;
    while(i < LEN(arrA) && j < LEN(arrB))
        if(arrA[i] < arrB[j])
            cout<<arrA[i++]<<" ";
        else
            cout<<arrB[j++]<<" ";

    while(i < LEN(arrA))
            cout<<arrA[i++]<<" ";

    while(j < LEN(arrB))
            cout<<arrB[j++]<<" ";
    
    cout<<"\n";
    return 0;
}
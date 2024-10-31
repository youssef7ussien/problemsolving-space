/**
 * Title: "Number of Equal", Uncategorized problem. 
 * Date: Friday, 08 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
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

    Long counter = 0;
    for(int i = 0, j = 0 ; j < LEN(arrB) ;) {
        int cnt = 0, num = 1, k = j + 1;
        while(k < LEN(arrB) && arrB[j] == arrB[k])
            num++, k++;

        while(i < LEN(arrA) && arrA[i] < arrB[j])
            i++;

        while(i < LEN(arrA) && arrA[i] == arrB[j])
            cnt++, i++;
        
        counter += 1LL * cnt * num, j = k;
    }

    cout<<counter<<"\n";
    return 0;
}
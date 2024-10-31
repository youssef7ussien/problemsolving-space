/**
 * Title: "X-Sum", Codeforces problem. 
 * Date: Tuesday, 10 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef vector<int>             VI;


int getTotalSum(const vector<VI> arr, int X,int Y)
{
    int sum = 0;
    
    for(int i = X, j = Y ; i < LEN(arr) && j < LEN(arr[0]) ; i++, j++)
        sum += arr[i][j];

    for(int i = X, j = Y ; i >= 0 && j >= 0 ; i--, j--)
        sum += arr[i][j];
    
    for(int i = X, j = Y ; i >= 0 && j < LEN(arr[0]) ; i--, j++)
        sum += arr[i][j];
    
    for(int i = X, j = Y ; i < LEN(arr) && j >= 0 ; i++, j--)
        sum += arr[i][j];
    
    return sum - arr[X][Y] * 3;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, M;
        cin>>N>>M;
        
        vector<VI> arr(N, VI(M));
        for(auto &it1 : arr)
            for(auto &it2 : it1)
                cin>>it2;
        
        int result = 0;
        for(int i = 0 ; i < N ; i++)
            for(int j = 0 ; j < M ; j++)
                result = max(result, getTotalSum(arr, i, j));

        cout<<result<<"\n";
    }
    
    return 0;
}
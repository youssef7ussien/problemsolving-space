/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


bool check(string T,const string &P, const VI &arr, int middle)
{
    for(int i = 0 ; i < middle ; i++)
        T[arr[i] - 1] = '.';
    
    for(int i = 0, j = 0 ; i < LEN(T) ; i++) {
        j += (T[i] == P[j]);
        if(j == LEN(P))
            return true;
    }
        
    return false;
}

int binarySearch(const string &T, const string &P, const VI &arr)
{
    int left = 0, right = LEN(arr) - 1;
    while(left < right) {
        int middle = left + (right - left + 1) / 2;

        check(T, P, arr, middle) ? left = middle : right = middle - 1;
    }

    return left;
}

int main()
{
    FAST_IO;
    
    string T, P;
    cin>>T>>P;
    
    VI arr(LEN(T));
    for(auto &it : arr)
        cin>>it;
    
    cout<<binarySearch(T, P, arr)<<"\n";
    return 0;
}
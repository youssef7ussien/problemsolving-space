/**
 * Title: "String Game", Codeforces problem. 
 * Date: Monday, 07 March 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


bool check(string strT,const string &strP,const VI &perm, int middle)
{
    for(int i = 0 ; i < middle ; i++)
        strT[perm[i] - 1] = '.';

    for(int i = 0, j = 0 ; i < LEN(strT) ; i++) {
        j += (strT[i] == strP[j]);
        if(j == LEN(strP))
            return true;
    }
    
    return false;
}

int binarySearch(const string &strT,const string &strP, const VI &perm)
{
    int left = 0, right = LEN(perm) - 1;
    while(left < right) {
        int middle = left + (right - left + 1) / 2;
        
        check(strT, strP, perm, middle) ? left = middle : right = middle - 1;
    }

    return left;
}

int main()
{
    FAST_IO;
    
    string strT, strP;
    cin>>strT>>strP;

    VI perm(LEN(strT));
    for(auto &it : perm)
        cin>>it;

    cout<<binarySearch(strT, strP, perm)<<"\n";
    return 0;
}
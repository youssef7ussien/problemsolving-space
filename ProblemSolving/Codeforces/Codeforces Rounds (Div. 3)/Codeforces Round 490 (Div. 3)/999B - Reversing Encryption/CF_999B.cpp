/**
 * Title: "Reversing Encryption", Codeforces problem. 
 * Date: Tuesday, 01 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)

set<int> getDivisors(int N)
{
    // without 1
    set<int> divisors;
    for(int i = 2 ; i * i <= N ; i++)
        if(N % i == 0) {
            divisors.insert(i);
            if(N / i != i)
                divisors.insert(N / i);
        }

    divisors.insert(N);
    return divisors;
}

int main()
{   
    FAST_IO;
    
    int N;
    string str;
    
    cin>>N>>str;

    set<int> divisors = getDivisors(N);

    for(auto &it : divisors)
        reverse(str.begin(), str.begin() + it);

    cout<<str<<"\n";
    return 0;
}
/**
 * Title: "Divide by three, multiply by two", Codeforces problem. 
 * Date: Monday, 15 August 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;
typedef vector<Long>            VL;


int main()
{
    FAST_IO;
    
    int N;
    cin>>N;
    
    VL arr(N);
    for(auto &it : arr)
        cin>>it;
    
    auto countDivBy3 = [](Long num){
        int counter = 0;
        while(num % 3 == 0)
            counter++, num /= 3;
        return counter;
    };

    sort(ALL(arr), [countDivBy3](const Long &a, const Long &b){ 
        return countDivBy3(a) > countDivBy3(b) || (countDivBy3(a) == countDivBy3(b) && a < b);
    });
    
    for(auto &it : arr)
      cout<<it<<" ";
    cout<<"\n";

    return 0;
}
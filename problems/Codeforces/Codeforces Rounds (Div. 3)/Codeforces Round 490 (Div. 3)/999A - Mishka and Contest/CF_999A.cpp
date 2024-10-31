/**
 * Title: "Mishka and Contest", Codeforces problem. 
 * Date: Tuesday, 01 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)                     ((int)((v).size()))
#define TEST_CASES(T)               int T; cin>>T; while(T--)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)


int main()
{   
    FAST_IO;

    int N, K;
    cin>>N>>K;
    deque<int> numbers(N);

    for (auto &it : numbers)
        cin>>it;

    while(!numbers.empty())
        if(numbers.front() <= K)
            numbers.pop_front();
        else if(numbers.back() <= K)
            numbers.pop_back();
        else
            break;

    cout<<(N - SIZE(numbers))<<"\n";

    return 0;
}
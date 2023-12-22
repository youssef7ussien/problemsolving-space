#include <bits/stdc++.h>

using namespace std;

#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define TEMP_CIN(T)       int T; cin>>T;
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long         Long;
typedef vector<int>       VI;
typedef priority_queue<int, VI, greater<int>> P_QUEUE;

int main()
{
    FAST_IO;

    TEST_CASES(T) {
        int N;
        cin>>N;
        P_QUEUE numbers;

        for(int i=0 ; i<N ; i++)
        {
            TEMP_CIN(temp);
            numbers.push(temp);
        }

        int minimum = numbers.top();
        while(SIZE(numbers) > 1) 
        {
            int top = numbers.top();
            numbers.pop();
            minimum = max(minimum, numbers.top() - top);
        }

        cout<<minimum<<"\n";
    }

    return 0;
}
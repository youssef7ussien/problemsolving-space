/**
 * Title: "Unequal Array", Codeforces problem. 
 * Date: Saturday, 23 April 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define SIZE(v)                 ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<PII>             VII;


int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;

        VI numbers(N), temp;
        for(auto &it : numbers)
            cin>>it;

        int counter = 0;
        for(int i = 0 ; i < N - 1 ; i++)
            if(numbers[i] == numbers[i + 1])
                counter++, temp.push_back(i);

        if(counter <= 1)
            cout<<"0"<<"\n";
        else if (temp[0] + 1 == temp[SIZE(temp) - 1])
            cout<<"1"<<"\n";
        else
            cout<<((temp[SIZE(temp) - 1]) - (temp[0] + 1))<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Eating Candies", Codeforces problem. 
 * Date: Thursday, 21 April 2022 
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

        VI weights(N);
        for(auto &it : weights)
            cin>>it;

        int left = 1, right = N - 1;
        Long countA = weights[0], countB = 0;
        PII counter = {0, 0};
        bool turn = false;

        while(left <= right) {
            if(turn) {
                if(countA == countB)
                    counter.first = left;

                countA += weights[left++];
                while(countA < countB && left <= right)
                    countA += weights[left++];

                if(countA == countB)
                    counter.first = left;
                
                turn = false;
            }
            else {
                if(countA == countB)
                    counter.second = (N - 1) - right;

                countB += weights[right--];
                while(countB < countA && left <= right)
                    countB += weights[right--];

                if(countA == countB)
                    counter.second = (N - 1) - right;
                
                turn = true;
            }
        }
        
        if(countA == countB)
            counter = {(N - 1) - right, left};

        cout<<(counter.first + counter.second)<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Lets Play the Hat", Codeforces problem. 
 * Date: Thursday, 05 May 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define UP(A, B)                int(A / B + (A % B != 0))
#define DOWN(A, B)              int(A / B)


void print(deque<int> &people, int count)
{
    cout<<count<<" ";
    while(count--) {
        cout<<people.front()<<" ";
        people.push_back(people.front()), people.pop_front();
    }
    cout<<"\n";
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N, M, K;
        cin>>N>>M>>K;

        deque<int> people(N);
        for(int i = 0 ; i < N ; i++)
            people[i] = i + 1;

        while(K--) {
            for(int i = 0 ; i < N % M ; i++)
                print(people, UP(N, M));

            for(int i = 0 ; i < M - N % M ; i++)
                print(people, DOWN(N, M));

            if(N % M != 0)
                for(int i = (N % M) * UP(N, M) ; i < N ; i++)
                    people.push_front(people.back()), people.pop_back();
        }
        
        cout<<"\n";
    }
    
    return 0;
}
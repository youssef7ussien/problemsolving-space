/**
 * Title: "Static Range Queries", Codeforces GYM problem.
 * Author: Youssef Hussien (https://codeforces.com/profile/youssef7ussien)
 * Date: Saturday, 20 August 2022
 * Contest: USACO Guide Problem Submission (https://codeforces.com/gym/102951)
 * 
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                  ((v).begin()), ((v).end())
#define R_ALL(v)                ((v).rbegin()), ((v).rend())
#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FF                      first
#define SS                      second
#define INF                     1e9

typedef long long               Long;
typedef pair<int, int>          PII;
typedef vector<int>             VI;
typedef vector<Long>            VL;
typedef vector<PII>             VII;

 
struct BIT {
    vector <Long> tree;
    int n;
 
    BIT(int N){
        n = N + 1;
        tree.assign(n + 10, 0);
    }
 
    int lastBit(int index) {
        return (index & -index);
    }
 
    void add(int index, int value) {
        for(++index ;  index < n ; index += lastBit(index))
            tree[index] += value;
    }

    void add(int left, int right, int value) {
        add(left, value), add(right + 1, -value);
    }
 
    Long query(int index) {
        Long sum = 0;
        for(++index ;  index > 0 ; index -= lastBit(index))
            sum += tree[index];
        return sum;
    }
 
    Long query(int left, int right) {
        if(left > right)
            swap(left, right);
        return query(right) - query(left - 1);
    }
};
 
int main()
{
    FAST_IO;
    
    // TODO: Not implemented yet.

    int N, Q;
    cin>>N>>Q;
    
    BIT bit1(12);
    BIT bit2(12);

    while(N--) {
        int l, r, v;
        cin>>l>>r>>v;
        
        bit1.add(l, r, v);
        bit2.add(l, r, 5);
    }

    while(Q--) {
        int l, r;
        cin>>l>>r;

        cout<<""<<"\n";
    }
    
    return 0;
}
/**
 * Title: "Maximum Crossings (Hard Version)", Codeforces problem. 
 * Date: Monday, 16 May 2022 
 * hint: use inversion count by Binary index tree/Fenweck tree (https://codeforces.com/blog/entry/86294)
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;


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
        index++;
        while(index <= n)
            tree[index] += value, index += lastBit(index);
    }
 
    Long query(int index) {
        index++;
        Long sum = 0;
        while(index)
            sum += tree[index], index -= lastBit(index);
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

    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI numbers(N);
        for(auto &it : numbers)
            cin>>it;
        
        Long result = 0;
        BIT BITree(N + 10);

        for(auto &it : numbers)
            result += BITree.query(it, N), BITree.add(it, 1);

        cout<<result<<"\n";
    }
    
    return 0;
}
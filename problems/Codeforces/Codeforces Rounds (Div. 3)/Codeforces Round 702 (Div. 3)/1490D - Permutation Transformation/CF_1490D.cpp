/**
 * Title: "Permutation Transformation", Codeforces problem. 
 * Date: Sunday, 03 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


void buildTree(int left, int right, int current, const VI &arr, VI &depth)
{
    if(left > right)
        return;
    else if(left == right) 
        { depth[left] = current; return; }

    int index = max_element(arr.begin() + left, arr.begin() + right + 1) - arr.begin();

    depth[index] = current;

    buildTree(left, index - 1, current + 1, arr, depth);
    buildTree(index + 1, right, current + 1, arr, depth);
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        VI arr(N), depth(N);
        for(auto &it : arr)
            cin>>it;
        
        buildTree(0, N - 1, 0, arr, depth);

        for(auto &it : depth)
          cout<<it<<" ";
        cout<<"\n";
    }
    
    return 0;
}
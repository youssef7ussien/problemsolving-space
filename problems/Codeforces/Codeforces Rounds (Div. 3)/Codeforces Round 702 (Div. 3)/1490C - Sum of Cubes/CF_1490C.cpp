/**
 * Title: "Sum of Cubes", Codeforces problem. 
 * Date: Saturday, 02 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;


bool binarySearch(int A, Long X) {
    int left = 1, right = cbrt(X);
    while(left <= right) {
        int middle = left + (right - left) / 2;

        Long result = pow(A, 3) + pow(middle, 3);
        if(result == X)
            return true;
        
        result < X ? left = middle + 1 : right = middle - 1;
    }

    return false;
}

bool formula(int A, Long X)
{
    Long diff = X - 1LL * A * A * A, B = cbrt(diff);

    return B * B * B == diff && diff != 0;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        Long X;
        cin>>X;

        bool can = false;
        for(int i = 1 ; 1LL * i * i * i <= X ; i++)
            if(formula(i, X)) // or use binarySearch(i, X)
                { can = true; break; }

        cout<<(can ? "YES" : "NO")<<"\n";
    }
    
    return 0;
}
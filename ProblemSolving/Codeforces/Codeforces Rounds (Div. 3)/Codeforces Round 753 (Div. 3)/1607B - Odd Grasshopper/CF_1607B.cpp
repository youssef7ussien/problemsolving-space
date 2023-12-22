/**
 * EX 1: Assume X = 10, N = 9
 * 
 * N:    1 ---> 2 ----> 3 ----> 4 ----> 5 ---> 6 ----> 7 ----> 8 ----> 9 
 * X: 10 ---> 9 ---> 11 ---> 14 ---> 10 ---> 5 ---> 11 ---> 18 ---> 10 ---> 1
 *
 *  1. X appears every four times
 * then when X is even: 
 *          1. (N % 4 == 0) ===> X
 *          2. (N % 4 == 1) ===> X - N
 *          3. (N % 4 == 2) ===> X + 1
 *          4. (N % 4 == 3) ===> X + (N + 1)
 *
 * EX 2: Assume X = 13, N = 9
 * 
 * N:     1 ----> 2 ----> 3 ----> 4 ---> 5 ----> 6 ----> 7 ---> 8 ----> 9 
 * X: 13 ---> 14 ---> 12 ---> 9 ---> 13 ---> 18 ---> 12 ---> 5 ---> 14 ---> 22
 *
 *  1. X appears every four times
 * then when X is odd: 
 *          1. (N % 4 == 0) ===> X
 *          2. (N % 4 == 1) ===> X + N
 *          3. (N % 4 == 2) ===> X - 1
 *          4. (N % 4 == 3) ===> X - (N + 1)
*/
#include <bits/stdc++.h>

#define TEST_CASES(T)     int T; std::cin>>T; while(T--)
#define FAST_IO           std::ios_base::sync_with_stdio(false), std::cin.tie(NULL)

typedef long long         Long;

Long sign(const Long &X,const Long &N) 
{
    return (N * (-1 * (X % 2 == 0 ? -1 : 1)));
}

int main()
{
    FAST_IO;

    TEST_CASES(T) {
        Long X, N;
        std::cin>>X>>N;

        const std::map<int, Long> operations = {
            {0, X}, 
            {1, X - sign(X, N)}, 
            {2, X + sign(X, 1)}, 
            {3, X + sign(X, N+1)},
        };

        std::cout<<operations.at(N % 4)<<"\n";
    }

    return 0;
}
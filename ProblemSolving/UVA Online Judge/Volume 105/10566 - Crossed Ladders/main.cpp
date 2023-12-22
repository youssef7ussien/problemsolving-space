#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
#define Pytha_EQ(X, Y) sqrt((X*X)-(Y*Y))

/**
 *    | *                |
 *    |   *  X           |
 *    |     *        Y  *|
 *    |       *       *  |
 *    |         *  *     |  B
 *  A |         * *      |
 *    |      *   |  *    |
 *    |   *    C |    *  |
 *    |*         |      *|
 *    |------------------|
 *             W
 *
 * - with "Pythagorean theorem"
 *      1- A = sqrt(X^2 - W^2)
 *      2- B = sqrt(Y^2 - W^2)
 *
 * - 1/A + 1/B = 1/C
 * => (A * B) / (A + B) = C => 1
 *
 * search for W that makes equation 1 true (with Binary Seach)
 * 'W' is an inverse relationship with 'C'
 */

double check(double X, double Y, double middle)
{
    double A = Pytha_EQ(X, middle), B = Pytha_EQ(Y, middle);

    return ((A * B) / (A + B));
}

double streetWidth(double X,double Y, double C)
{
    double left=0.0, right=max(X, Y);

    while(right-left > EPS) {
        double middle=(left+right)/2;

        check(X, Y, middle) > C ? left=middle : right=middle;
    }

    return left;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    double X, Y, C;

    while(cin>>X>>Y>>C)
        cout<<fixed<<setprecision(3)<<streetWidth(X, Y, C)<<"\n";

    return 0;
}

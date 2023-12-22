/** The area given are s1, s2 and s3.
 * Let a, b and c be the lengths of the sides that have one common vertex.
 * where s1 = a*b , s2 = a*c , s3 = b*c
 * then
 *   |- a = s1/b  &  a = s2/c
 *   |- b = s1/a  &  b = s3/c
 *   |- c = s2/a  &  c = s3/b
 *
 * 1- a = s1/b = s1/(s3/c) = s1/(s3/(s2/a)) = (s1 * s2)/(s3 * a) = sqrt((s1 * s2) / s3)
 * 2- b = s1/a = s1/(s2/c) = s1/(s2/(s3/b)) = (s1 * s3)/(s2 * b) = sqrt((s1 * s3) / s2)
 * 3- c = s2/a = s2/(s1/b) = s2/(s1/(s3/c)) = (s2 * s3)/(s1 * c) = sqrt((s2 * s3) / s1)
 */

#include <bits/stdc++.h>

using namespace std;


int main()
{
    int s1, s2, s3;
    cin>>s1>>s2>>s3;

    cout<<((sqrt((s1 * s2) / s3) + sqrt((s1 * s3) / s2) + sqrt((s2 * s3) / s1)) * 4)<<"\n";

    return 0;
}

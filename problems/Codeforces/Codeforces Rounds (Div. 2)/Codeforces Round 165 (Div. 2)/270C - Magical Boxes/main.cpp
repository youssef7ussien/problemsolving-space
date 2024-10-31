#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long Long;

// Implementation
/*int smallestMagicalBoxIMP(const vector<pair<int,int>> &boxes)
{
    int newLength=0, maxLength=0;
    for(auto &it : boxes)
    {
        int numBoxes=1, length=0;
        while(numBoxes<it.second)
            length++, numBoxes*=4;

        newLength=max(newLength, it.first+length);
        maxLength=max(maxLength, it.first);
    }

    return newLength==maxLength ? newLength+1 : newLength;
}
*/

bool isValid(const vector<pair<int,int>> &boxes, Long newSide)
{
    for(auto &it : boxes)
    {
        if(newSide<=it.first)
            return false;
        if(newSide-it.first>15) // 4^15 > 1e9
            continue;
        if(pow(4, newSide-it.first)<it.second)
            return false;
    }

    return true;
}

// Binary Search
Long smallestMagicalBoxBS(const vector<pair<int,int>> &boxes)
{
    Long left=0, right=1e10;
    while(left<=right)
    {
        Long middle=(left+right)/2;
        isValid(boxes, middle) ? right=middle-1 : left=middle+1;
    }

    return left;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N;
    cin>>N;
    vector<pair<int,int>> boxes(N);

    for(auto &it : boxes)
        cin>>it.first>>it.second;

//    cout<<smallestMagicalBoxIMP(boxes)<<"\n";
    cout<<smallestMagicalBoxBS(boxes)<<"\n";

    return 0;
}


/**
 * hint: https://www.quora.com/What-is-the-correct-approach-to-solve-the-SPOJ-problem-Aggressive-cow
 * hint: https://www.youtube.com/watch?v=2R9L6mVal9U
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define SIZE(v) ((int)v.size())

bool checkDistance(const vector<int> &stallsPos,const int &cows,const int &distance)
{
    int counter=1, lastPos=stallsPos[0];
    for(int i=1 ; i<SIZE(stallsPos) ; i++)
        if(stallsPos[i]-lastPos>=distance)
        {
            if(++counter==cows) return true;
            lastPos=stallsPos[i];
        }

    return false;
}

int minimumDistance(vector<int> stallsPos,const int &cows)
{
    sort(stallsPos.begin(), stallsPos.end());
    int left = 0, right = stallsPos[SIZE(stallsPos) - 1] - stallsPos[0], middle;
    while(right - left > 1)
    {
        middle = left + (right - left) / 2;
        checkDistance(stallsPos, cows, middle) ? left = middle : right = middle;
    }
    return left;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,cows;
        cin>>N>>cows;
        vector<int> stallsPos(N);
        for(auto &it : stallsPos)
            cin>>it;
        cout<<minimumDistance(stallsPos,cows)<<endl;
    }
    return 0;
}

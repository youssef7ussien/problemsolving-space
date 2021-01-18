// hint : https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleInHistogram(const vector<int> &row)
{
    stack<int> result;
    int topIndex;
    int maxArea=0, area=0, i=0;
    while(i<(int)row.size())
    {
        if(result.empty() || row[result.top()]<=row[i])
            result.push(i++);
        else
        {
            topIndex=result.top();
            result.pop();
                // row[topIndex] => is length , (result.empty() ? i : i-result.top()-1) => is width
            area=row[topIndex]*(result.empty() ? i : i-result.top()-1);
            maxArea=max(maxArea,area);
        }
    }

    while(result.size())
    {
        topIndex=result.top();
        result.pop();
            // row[topIndex] => is length , (result.empty() ? i : i-result.top()-1) => is width
        area=row[topIndex]*(result.empty() ? i : i-result.top()-1);
        maxArea=max(maxArea,area);
    }

    return maxArea;
}

int AreaOfLargestBlock(const int &S,vector<vector<int>> points)
{
    for(int j=0 ; j<S ; j++) // first row
        points[0][j]=!points[0][j];

    int maxArea=largestRectangleInHistogram(points[0]);
    for(int i=1 ; i<S ; i++)
    {
        for(int j=0 ; j<S ; j++)
            points[i][j]=(!points[i][j] ? points[i-1][j]+1 : !points[i][j]);

        maxArea=max(maxArea,largestRectangleInHistogram(points[i]));
    }

    return maxArea;
}

int main()
{
    int P;
    cin>>P;

    while(P--)
    {
        int S, N;
        cin>>S>>N;

        vector<vector<int>> points(S,vector<int>(S));
        for(int i=0 ; i<N ; i++)
        {
            int r1, c1 ,r2 , c2;
            cin>>r1>>c1>>r2>>c2;

            for(int r=r1-1 ; r<r2 ; r++)
                for(int c=c1-1 ; c<c2 ; c++)
                    points[r][c]=1;
        }
        cout<<AreaOfLargestBlock(S,points)<<endl;
    }

    return 0;
}

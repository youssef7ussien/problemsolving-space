#include <bits/stdc++.h>

using namespace std;

pair<int,int> newPoint(pair<int,int> point1, pair<int,int> point2,int N)
{
    if(point1.first==point2.first && point1.first<N-1)
        return make_pair(point1.first+1, point1.second);

    if(point1.first==point2.first && point1.first>0)
        return make_pair(point1.first-1, point1.second);

    if(point1.second==point2.second && point1.second<N-1)
        return make_pair(point1.first, point1.second+1);

    if(point1.second==point2.second && point1.second>0)
        return make_pair(point1.first, point1.second-1);

    return make_pair(point2.first, point1.second);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int T; cin>>T;
    while(T--)
    {
        int N; cin>>N;

       vector<pair<int,int>> points;

        for(int i=0 ; i<N ; i++)
            for(int j=0 ; j<N ; j++)
            {
                char c; cin>>c;
                if(c=='*')
                    points.push_back(make_pair(i,j));
            }

        points.push_back(newPoint(points[0],points[1],N));
        points.push_back(newPoint(points[1],points[0],N));

        for(int i=0 ; i<N ; i++)
        {
            for(int j=0 ; j<N ; j++)
            {
                if(find(points.begin(), points.end(), make_pair(i,j))!=points.end())
                    cout<<"*";
                else
                    cout<<".";
            }
            cout<<"\n";
        }
    }
    return 0;
}


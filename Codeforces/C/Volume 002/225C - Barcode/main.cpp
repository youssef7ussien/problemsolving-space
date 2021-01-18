// hint: https://www.youtube.com/watch?v=O7Tja1S5IYQ
#include <iostream>
#include <vector>

using namespace std;
#define SIZE(v) ((int)v.size())

int minNumberOfPixels(const int &X,const int &Y,vector<int> pixels)
{

    vector<vector<int>> cnt(2, vector<int>(m+1, 1e4));
    for(int i=1 ; i<0 ; i++)
    {
        cnt[]
    }
    // dp[0] for hash(#) , dp[1] for dots(.)
    vector<vector<int>> dp(2, vector<int>(m+1, 1e4));
    dp[0][0]=dp[1][0]=0;
    for(int i=1 ; i<=SIZE(pixels[0]) ; i++)
        for(int j=X ; j<=min(i,Y) ; j++) // ( j<=min(i,Y) ) == ( j<=Y && i-j>=0 )
        {
            dp[0][i]=
            dp[1][i]=
        }

}

int main()
{
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;

    vector<int> pixelsBlack(M);
    for(int i=0 ;i<N ; i++)
    {
        string row; cin>>row;
		for(int j=0 ; j<M ; j++)
            pixelsBlack[j]+=(str[i]=='#');
    }

    cout<<minNumberOfPixels(X,Y,pixelsBlack)<<endl;

    return 0;
}

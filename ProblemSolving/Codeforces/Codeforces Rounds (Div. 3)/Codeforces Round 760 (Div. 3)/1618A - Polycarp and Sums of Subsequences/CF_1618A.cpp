/**
 * Title: "Polycarp and Sums of Subsequences" problem. 
 * Date: Tuesday, 14 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define INF               1e9

typedef long long         Long;
typedef vector<int>       VI;

void solve_2(const  VI &numbers) // Brute force solution
{
    int i = 0, j = 1, k = 2;

    for(i=0 ; i<6 ; i++)
        for(j=i+1 ; j<6 ; j++)
            for(k=j+1 ; k<6 ; k++)
                if(numbers[i]+numbers[j]+numbers[k] == numbers[6])
                {
                    cout<<numbers[i]<<" "<<numbers[j]<<" "<<numbers[k]<<"\n";
                    return ;
                }
}

void solve(const  VI &numbers)
{
    cout<<numbers[0]<<" "<<numbers[1]<<" "<<(numbers[6] - numbers[1] - numbers[0])<<"\n";
}

int main()
{   
    FAST_IO;
    
    TEST_CASES(T) 
    {
        VI numbers(7);
        for(auto &it : numbers)
            cin>>it;
        
        solve(numbers);
    }
    
    return 0;
}
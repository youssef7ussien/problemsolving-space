/**
 * Title: "Binary Search", Codeforces problem. 
 * Date: Monday, 04 July 2022
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef long long               Long;


struct Assist {
    int t, z, y;
};

int countBallons(Assist assist, int time) {
    return (time / (assist.t * assist.z + assist.y)) * assist.z
            + min((time % (assist.t * assist.z + assist.y)) / assist.t, assist.z);
}

bool check(const vector<Assist> &arr, int M, int middle) {
    Long counter = 0;
    for(auto &it : arr)
        counter += countBallons(it, middle);

    return counter >= Long(M);
}

int main()
{
    FAST_IO;
    
    int M, N;
    cin>>M>>N;
    
    vector<Assist> arr(N);
    for(auto &it : arr)
        cin>>it.t>>it.z>>it.y;

    int left = 0, right = 1e9;
    while(left < right) {
        int middle = left + (right - left) / 2;
        check(arr, M, middle) ? right = middle : left = middle + 1;
    }
    
    cout<<right<<"\n";

    for(auto &it : arr) {
        int ballons = countBallons(it, right);
        cout<<min(ballons, max(M, 0))<<" ";
        M -= ballons;
    }
    cout<<"\n";

    return 0;
}
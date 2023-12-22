/**
 * Title: "Mirror Grid", Codeforces problem. 
 * Date: Thursday, 21 July 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)
typedef vector<int>             VI;


void swap(int &a, int &b, int &c, int &d) {
    int temp = a;
    a = b;
    b = c;
    c = d;
    d = temp;
}

vector<VI> rotate90(const vector<VI> &matrix)
{
    vector<VI> arr = matrix;
    int N = LEN(arr) - 1;

    for(int i = 0 ; i < LEN(arr) / 2 ; i++)
        for(int j = i ; j < LEN(arr) - i - 1 ; j++)
            swap(arr[i][j], arr[N - j][i], arr[N - i][N - j], arr[j][N - i]);
    
    return arr;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int N;
        cin>>N;
        
        vector<VI> matrix(N, VI(N));
        for(auto &it1 : matrix)
            for(auto &it2 : it1) {
                char ch;
                cin>>ch;

                it2 = ch - '0';
            }

        vector<VI> matrix90 = rotate90(matrix);
        vector<VI> matrix180 = rotate90(matrix90);
        vector<VI> matrix270 = rotate90(matrix180);

        int counter = 0;
        for(int i = 0 ; i < N / 2 ; i++)
            for(int j = i ; j < N - i - 1 ; j++) {
                int temp = (matrix[i][j] == 1) + (matrix90[i][j] == 1) + (matrix180[i][j] == 1) + (matrix270[i][j] == 1);
                if(temp != 4)
                    counter += (temp == 2 ? 2 : min(1, temp));
            }

        cout<<counter<<"\n";
    }
    
    return 0;
}
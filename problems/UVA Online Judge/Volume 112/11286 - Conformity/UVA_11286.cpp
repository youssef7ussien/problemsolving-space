/**
 * Title: "Conformity", UVA Online Judge problem. 
 * Date: Saturday, 18 December 2021 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)     freopen(file, "r", stdin)
#define FILE_OUT(file)    freopen(file, "w", stdout)
#define PB                push_back
#define FF                first
#define SS                second

typedef long long         Long;
typedef vector<int>       VI;

int main()
{
    #ifdef DEBUG
        FILE_IN("__UVA_11286_input.txt");
        FILE_OUT("__UVA_11286_output.txt");
    #endif
    
    FAST_IO;
    
    int N;
    while((cin>>N) && N!=0)
    {
        vector<VI> students(N, VI(5));

        for(auto &student : students)
            for(auto &it : student)
                cin>>it;
        
        for(auto &it : students)
            sort(ALL(it));
        
        for(auto &it : students) { for(auto &it1 : it) cout<<it1<<" "; cout<<"\n"; }

        sort(ALL(students));

        int counter = 1;
        multiset<int, greater<int>> maxCounter;
        for(int i=0 ; i<SIZE(students)-1 ; i++)
        {
            if(students[i] != students[i+1])
                maxCounter.insert(counter), counter=0;
            counter++;
        }
        maxCounter.insert(counter);

        cout<<maxCounter.count(*maxCounter.begin()) * *maxCounter.begin()<<"\n";
    }

    return 0;
}
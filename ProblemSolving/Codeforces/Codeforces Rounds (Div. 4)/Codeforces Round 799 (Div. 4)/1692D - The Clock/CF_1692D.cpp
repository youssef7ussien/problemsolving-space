/**
 * Title: "The Clock", Codeforces problem. 
 * Date: Tuesday, 14 June 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define LEN(v)                  ((int)((v).size()))
#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)


int convertTime(string time) {
    return stoi(std::string() + time[0] + time[1]) * 60 + stoi(std::string() + time[3] + time[4]);
}

string convertTime(int minutes) {
    string hour = to_string((minutes / 60) % 24), minute = to_string(minutes % 60);
    return (LEN(hour) == 1 ? "0" : "") + hour + ":" + (LEN(minute) == 1 ? "0" : "") + minute;
}

int main()
{
    FAST_IO;
    
    TEST_CASES(T) {
        int X;
        string time;
        cin>>time>>X;

        set<string> times;
        while(times.count(time) == 0)
            times.insert(time), time = convertTime(convertTime(time) + X);
        
        int counter = 0;
        for(auto &it : times)
            counter += (it[0] == it[4] && it[1] == it[3]);
        
        cout<<counter<<"\n";
    }
    
    return 0;
}
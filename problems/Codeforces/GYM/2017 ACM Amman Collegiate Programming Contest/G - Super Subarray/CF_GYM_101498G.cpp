#include <bits/stdc++.h>

using namespace std;

#define TEST_CASES(T)           int T; cin>>T; while(T--)
#define CIN(T)                  int T; cin>>T;
#define FAST_IO                 ios_base::sync_with_stdio(false), cin.tie(NULL)

typedef long long               Long;
typedef vector<int>             VI;
typedef vector<Long>            VL;


Long GCD(Long a, Long b) {
    return b == 0 ? a : GCD(b, a % b);
}

Long LCM(Long a, Long b) {
    return a / GCD(a, b) * b;
}

int main()
{
    FAST_IO;

    TEST_CASES(T) {
        int N;
        cin>>N;

        VI numbers(N);
        VL prefix(N);
        
        for(int i = 0 ; i < N ; i++) {
            cin>>numbers[i];
            prefix[i] = numbers[i] + (i == 0 ? 0 : prefix[i - 1]);
        }

        int counter = N;
        for(int i = 0 ; i < N ; i++) {
            Long num = numbers[i];
            for(int j = i + 1 ; j < N ; j++) {
                num = LCM(num, numbers[j]);
                
                if(num > prefix.back())
                    break;

                counter += ((prefix[j] - (i == 0 ? 0 : prefix[i - 1])) % num == 0);
            }
        }

        cout<<counter<<"\n";
    }

    return 0;
}

/**
 * Title: "Equal Sums", Codeforces problem. 
 * Date: Friday, 04 February 2022 
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)                      ((v).begin()), ((v).end())
#define SIZE(v)                     ((int)((v).size()))
#define LOOP(start, stop, steps)    for(int _i=start ; (steps>0 ? _i<stop : _i>stop) ; _i+=steps)
#define FAST_IO                     ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)               freopen(file, "r", stdin)
#define FILE_OUT(file)              freopen(file, "w", stdout)
#define INF                         1e9

typedef long long                   Long;
typedef vector<int>                 VI;

struct Assist {
    int sum = 0, seq = 0, index = 0;

    Assist() {}
    Assist(int sum,int seq,int index) : sum(sum), seq(seq), index(index) {}

    bool operator<(const Assist &item) const {
		return sum != item.sum ? sum < item.sum : 
            seq != item.seq ? seq < item.seq : index < item.index;
	}
};

void result(const vector<Assist> &items)
{
    LOOP(0, SIZE(items) - 1, 1)
        if(items[_i].sum == items[_i + 1].sum &&  items[_i].seq != items[_i + 1].seq) {
            cout<<"YES"<<"\n"
                <<items[_i].seq<<" "<<items[_i].index<<"\n"
                <<items[_i + 1].seq<<" "<<items[_i + 1].index<<"\n";
            return;
        }

    cout<<"NO"<<"\n";
}

int main()
{  
    FAST_IO;
    
    int K;
    cin>>K;
    
    vector<Assist> items;
    for(int i = 0 ; i < K ; i++) {
        int N, sum = 0;
        cin>>N;

        VI sequence(N);
        for(auto &it : sequence) {
            cin>>it; sum += it;
        }

        for(int j = 0 ; j<SIZE(sequence) ; j++)
            items.push_back(Assist(sum - sequence[j], i + 1, j + 1));
    }

    sort(ALL(items));
    
    result(items);
    
    return 0;
}
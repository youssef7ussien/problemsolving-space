#include <iostream>

using namespace std;
#define INF 1e6

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("collectingofficer.in", "r", stdin);

    int T=0;
    cin>>T;

    while(T--)
    {
        int N;
        string str;

        cin>>N>>str;

        int range=INF;

        for(int i=0 ; i<N ; i++)
        {
            int alpha='A';

            for(int j=i ; j<N ; j++)
                if(str[j] == (char)alpha)
                {
                    if((char)alpha == 'Z')
                        { range=min(range, j-i+1); break; }

                    alpha++;
                }
        }

        cout<<range<<"\n";
    }

    return 0;
}


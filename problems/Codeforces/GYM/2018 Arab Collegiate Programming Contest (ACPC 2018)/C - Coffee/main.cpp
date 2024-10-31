#include <iostream>
#include <map>

using namespace std;

struct Size {
    int small,medium,large;
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
//    freopen("coffee.in","r",stdin);

    int T=0;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        map<string, Size> coffee;
        for(int i=0 ; i<N ; i++)
        {
            string name; cin>>name;
            cin>>coffee[name].small>>coffee[name].medium>>coffee[name].large;
        }
        for(int i=0 ; i<M ; i++)
        {
            string str1,str2,str3;
            int result;
            cin>>str1>>str2>>str3;
            if(str2=="small")
                result=coffee[str3].small+(100/M);
            else if(str2=="medium")
                result=coffee[str3].medium+(100/M);
            else
                result=coffee[str3].large+(100/M);

            if(result%5==4)
                result++;
            else if(result%5==1)
                result--;
            cout<<str1<<" "<<result<<endl;
        }
    }
    return 0;
}

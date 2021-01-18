#include <iostream>

using namespace std;

void solve(const int &A,const int &B)
{
    pair<int,int> specialA={0,0}, specialB={0,0};

    if(A%10!=0)
        specialA.first=(A/10+1)*10, specialA.second=specialA.first-A;
    if(B%10!=0)
        specialB.first=(B/10+1)*10, specialB.second=specialB.first-B;



    if(specialB==make_pair(0,0) && specialB==specialA)
        cout<<A<<" x "<<B<<endl;
    else if(specialB==make_pair(0,0))
        cout<<specialA.first<<" x "<<B<<" - "<<specialA.second<<" x "<<B<<endl;
    else if(specialA==make_pair(0,0))
        cout<<specialB.first<<" x "<<A<<" - "<<specialB.second<<" x "<<A<<endl;
    else
        cout<<specialA.first<<" x "<<specialB.first<<" + "<<specialA.second<<" x "<<specialB.second<<" - "
            <<specialA.first<<" x "<<specialB.second<<" - "<<specialA.second<<" x "<<specialB.first<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int T=0;
    cin>>T;
    while(T--)
    {
        int A,B;
        cin>>A>>B;
        solve(A,B);
    }
    return 0;
}

// hint: https://youtu.be/VBaPXRcHIk8?list=PLPt2dINI2MIYrtHBahPW16S-Wz9wx24Nc&t=187

#include <bits/stdc++.h>

using namespace std;
#define SIZE(s) ((int)s.size())

void failureFunction(vector<int> &LPS, string str)
{
    for(int i=0 , j=1 ; j<SIZE(str) ; j++)
    {
        while(i>0 && str[i]!=str[j])
            i=LPS[i-1];

        if(str[i]==str[j])
            LPS[j]=++i;
    }
}

void print(const vector<int> &LPS)
{
    for(int i=1 ; i<SIZE(LPS) ; i++)
        if(LPS[i]!=0 && (i+1) % (i+1-LPS[i]) == 0)
            cout<<i+1<<" "<<((i+1) / (i+1-LPS[i]))<<"\n";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T, cases=1;
    cin>>T;

    while(T--)
    {
        string str;
        cin>>str>>str;

        vector<int> LPS(SIZE(str)); // Longest proper prefix which is also suffix

        cout<<"Test case #"<<cases++<<"\n";

        failureFunction(LPS, str);
        print(LPS);
    }
    return 0;
}

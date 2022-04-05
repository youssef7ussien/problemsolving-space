#include <iostream>
#include <stack>

using namespace std;

void increase(stack<int> &strips,int &counter,const int &height)
{
    counter++;
    strips.push(height);
}

int main()
{
    int N,counter=0;
    stack<int> strips;
    cin>>N;
    while(N--)
    {
        int height;
        cin>>height>>height;

        if(strips.empty())
            increase(strips,counter,height);
        else
        {
            while(!strips.empty() && strips.top()>height)
                strips.pop();

            if(strips.empty() || strips.top()!=height)
                increase(strips,counter,height);
        }
    }

    cout<<counter<<endl;

    return 0;
}

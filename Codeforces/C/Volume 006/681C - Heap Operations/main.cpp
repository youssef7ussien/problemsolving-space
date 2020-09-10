#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int,vector<int>,greater<int>> Queue;
typedef pair<int,string>  Pair;

const string INSERT ="insert";
const string GET    ="getMin";
const string REMOVE ="removeMin\n";
const string ENDL   ="\n";


void insertX(Queue &heap,Pair &result,int x)
{
    heap.push(x);
    result.second+=INSERT+" "+to_string(x)+ENDL;
    result.first++;
}

void removeMin(Queue &heap,Pair &result)
{
    if(heap.empty())
        { result.second+=INSERT+" 0"+ENDL; result.first++; }
    else
        heap.pop();

    result.second+=REMOVE;
    result.first++;
}
void getMinX(Queue &heap,Pair &result,int x)
{
    while(!heap.empty() && heap.top()<x)
        removeMin(heap,result);

    if(heap.empty() || heap.top()>x)
        insertX(heap,result,x);

    result.second+=GET+" "+to_string(x)+ENDL;
    result.first++;
}

int main()
{
    int N;
    cin>>N;
    Pair result;
    Queue heap;

    for(int i=0 ; i<N ; i++)
    {
        string opration;
        cin>>opration;

        if(opration==INSERT || opration==GET)
        {
            int x;
            cin>>x;
            opration==INSERT ? insertX(heap,result,x) : getMinX(heap,result,x);
        }
        else
            removeMin(heap,result);
    }

    cout<<result.first<<endl<<result.second;

    return 0;
}

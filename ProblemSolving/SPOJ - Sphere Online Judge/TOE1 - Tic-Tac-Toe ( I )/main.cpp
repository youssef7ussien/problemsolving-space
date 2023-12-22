// Explain problem : https://www.youtube.com/watch?v=VM2c3csK3Ps&t
#include <iostream>
#include <queue>

using namespace std;

bool isWin(const string &board)
{
    for(int i=0 ; i<9 ; i+=3)
        if(board[i]!='.' && board[i]==board[i+1] && board[i+1]==board[i+2])
            return true;
    for(int i=0 ; i<3 ; i++)
        if(board[i]!='.' && board[i]==board[i+3] && board[i+3]==board[i+6])
            return true;

    return (board[0]!='.' && board[0]==board[4] && board[4]==board[8])
        || (board[2]!='.' && board[2]==board[4] && board[4]==board[6]);
}

string isValidGame(const string &board)
{
    queue<pair<string, bool>> logic;

    logic.push({".........",true}); //Play X = true , Play Y = fasle
    while(logic.size())
    {
        pair<string, bool> currentState={logic.front().first,logic.front().second};
        logic.pop();

        if(currentState.first==board) return "yes";
        if(isWin(currentState.first)) continue;

        for(int i=0 ; i<9 ; i++)
            if(currentState.first[i]=='.')
            {
                currentState.first[i]=(currentState.second ? 'X' : 'O');
//                cout<<currentState.first<<endl;
                if(currentState.first[i]==board[i])
                    logic.push({currentState.first, !currentState.second});
                currentState.first[i]='.';
            }
    }
    return "no";
}

int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        string board="";
        for(int i=0 ; i<3 ; i++)
        {
            string row;
            cin>>row;
            board+=row;
        }
        cout<<isValidGame(board)<<endl;
    }
    return 0;
}

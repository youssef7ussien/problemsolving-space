#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:

    /**
     * This function is to solve the problem,
     * and the rest of the code is by default from the HackerRank.
     */
    static int comparator(Player a, Player b)  {
        if(a.score<b.score)
            return -1;
        else if(a.score==b.score)
        {
            if(a.name<b.name)
                return 1;
            else if(a.name>b.name)
                return -1;
            return 0;
        }
        return 1;
    }
};

bool compare(Player a, Player b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++)
    {
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}

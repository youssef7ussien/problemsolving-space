/**
 * Title: "Contest Scoreboard", UVA Online Judge problem.
 * Date: Friday, 17 December 2021
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define ALL(v)            ((v).begin()), ((v).end())
#define R_ALL(v)          ((v).rbegin()), ((v).rend())
#define SIZE(v)           ((int)((v).size()))
#define TEST_CASES(T)     int T; cin>>T; while(T--)
#define FAST_IO           ios_base::sync_with_stdio(false), cin.tie(NULL)
#define FILE_IN(file)     freopen(file, "r", stdin)
#define FILE_OUT(file)    freopen(file, "w", stdout)

typedef long long         Long;

struct Submission {
    int problem, time;
    char status;

    int penalty() const {
        return (status == 'C' ? time : (status == 'I' ? 20 : 0));
    }

    bool isAccepted() const {
        return (status == 'C');
    }
};

struct Contestant {
    int id = 0, solved = 0;
    vector<int> penalty = vector<int>(10);
    vector<bool> problems = vector<bool>(10);
    vector<Submission> submissions;

    void judge() {
        for(const auto &it : submissions)
        {
            if (problems[it.problem])
                continue;

            penalty[it.problem] += it.penalty();
            problems[it.problem] = it.isAccepted();
            solved += it.isAccepted();
        }
    }

    bool isActive() const {
        return SIZE(submissions) != 0;
    }

    int time() const {
        int total = 0;
        for (int i=1 ; i<10 ; i++)
            if(problems[i])
                total += penalty[i];
        return total;
    }

    bool operator<(const Contestant &contestant) const {
        return (solved < contestant.solved 
                || (solved == contestant.solved && time() > contestant.time()) 
                || (solved == contestant.solved && time() == contestant.time() && id > contestant.id));
    }
};

struct Board {
    vector<Contestant> contestants = vector<Contestant>(100);

    Board() {
        for(int i=0 ; i<100 ; i++)
            contestants[i].id = i+1;
    }

    void judgeAll() {
        for(auto &it : contestants)
            it.judge();
    }

    void printScore() {
        for(auto &it : contestants)
        {
            if (!it.isActive())
                continue;
            cout<<it.id<<" "<<it.solved<<" "<<it.time()<<"\n";
        }
    }
};

int main()
{
#ifdef DEBUG
    FILE_IN("__UVA_10258_input.txt");
    FILE_OUT("__UVA_10258_output.txt");
#endif

    FAST_IO;

    int T;
    cin>>T;
    cin.ignore(), cin.ignore();

    while(T--)
    {
        Board board;
        string line;
        while (getline(cin, line) && !line.empty())
        {
            int id;
            Submission submission;

            istringstream iss(line);
            iss>>id>>submission.problem>>submission.time>>submission.status;

            board.contestants[id-1].submissions.push_back(submission);
        }

        board.judgeAll();
        sort(R_ALL(board.contestants));
        board.printScore();

        cout<<(T ? "\n" : "");
    }

    return 0;
}
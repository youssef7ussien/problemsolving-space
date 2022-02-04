#include <bits/stdc++.h>

using namespace std;
#define SIZE(s) ((int)s.size())

struct Trie {
private:
    static int maxWords;
    map<char, Trie*> children;
    bool isLeaf;
    int counter;

    void print(Trie const& trie, string &prefix, const bool &skiped=false)
    {
        if(trie.isLeaf && skiped)
            cout<<prefix<<"\n";

        for(auto &it : trie.children)
            if(it.second != nullptr)
            {
                prefix+=it.first;
                print(*it.second, prefix, true);
                prefix.pop_back();
            }
    }

public:

    Trie() {
        isLeaf = false;
        counter = 0;
    }

    ~Trie() {
        maxWords=0;
        for (auto &it : children)
            delete it.second;
    }

    void insert(string str)
    {
        Trie *curr=this;
        for(auto &it : str)
        {
            if(curr->children[it] == nullptr)
                curr->children[it] = new Trie();

            curr = curr->children[it];
        }

        curr->isLeaf = true, curr->counter++, curr->maxWords++;
    }

    void printAllWords(string prefix)
    {
        if(this == nullptr)
            { cout<<"No match.\n"; return; }

        Trie *curr=this;
        for(auto &it : prefix)
        {
            curr = curr->children[it];
            if(curr == nullptr)
                { cout<<"No match.\n"; return; }
        }

        print(*curr, prefix);
    }
};

int Trie::maxWords=0;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int N;
    cin>>N;

    Trie trie;
    string str;

    while(N--)
        cin>>str, trie.insert(str);

    int M, cases=1;
    cin>>M;

    while(M--)
    {
        cin>>str;

        cout<<"Case #"<<cases++<<":\n";

        trie.printAllWords(str);
    }

    return 0;
}

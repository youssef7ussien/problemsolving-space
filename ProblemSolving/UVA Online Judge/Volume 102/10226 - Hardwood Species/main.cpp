#include <bits/stdc++.h>

using namespace std;
#define SIZE(s) ((int)s.size())

struct Trie {
private:
    map<char, Trie*> children;
    static int maxWords;
    int counter;
    bool isLeaf;

    void print(string &prefix, Trie const& trie)
    {
        if(trie.isLeaf)
            cout<<prefix<<fixed<<setprecision(4)<<" "<<(trie.counter * 100.0f / maxWords)<<"\n";

        for(auto &it : trie.children)
        {
            if(it.second != nullptr) {
                prefix+=it.first;
                print(prefix, *it.second);
                prefix.pop_back();
            }
        }
    }

public:
    Trie(): isLeaf(false), counter(0)
    {}

    ~Trie() {
        maxWords=0;
        for (auto &it : children)
            delete it.second;
    }

    void insert(string str)
    {
        Trie *curr=this;
        for(int i=0 ; i<SIZE(str) ; i++)
        {
            if(curr->children[str[i]] == nullptr)
                curr->children[str[i]] = new Trie();

            curr = curr->children[str[i]];
        }

        curr->isLeaf = true, curr->counter++, curr->maxWords++;
    }

    void printWordsWithPrecent() {
        string prefix="";
        print(prefix, *this);
    }
};

int Trie::maxWords=0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T=0;
    cin>>T;
    cin.get(), cin.ignore();

    while(T--)
    {
        Trie trie;
        string str;

        while(getline(cin, str) && str != "")
            trie.insert(str);

        trie.printWordsWithPrecent(); cout<<(T!=0 ? "\n" : "");
    }

    return 0;
}

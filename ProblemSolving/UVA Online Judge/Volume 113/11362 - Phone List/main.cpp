#include <bits/stdc++.h>

using namespace std;
#define SIZE(s) ((int)s.size())
#define TO_NUM(c) (c-'0')

struct Trie {
private:
    static const int CHILD_COUNT = 10;
    bool haveChild(Trie const* curr)
    {
        for (int i=0 ; i<CHILD_COUNT ; i++)
            if (curr->children[i] != nullptr)
                return true;    // child found

        return false;
    }

public:
    Trie *children[CHILD_COUNT];

    bool isLeaf;

    Trie() {
		isLeaf = false;
		for (int i = 0; i<CHILD_COUNT ; i++)
            this->children[i] = nullptr;
	}

    void insert(string str)
    {
        Trie *curr = this;
        for(int i=0 ; i<SIZE(str) ; i++)
        {
            if(curr->children[TO_NUM(str[i])] == nullptr)
                curr->children[TO_NUM(str[i])] = new Trie();

            curr = curr->children[TO_NUM(str[i])];
        }

        curr->isLeaf = true;
    }

    bool search(string str) // Not used
    {
        if(this == nullptr)
            return false;

        Trie *curr = this;
        for(int i=0 ; i<SIZE(str) ; i++)
        {
            curr = curr->children[TO_NUM(str[i])];
            if(curr == nullptr)
                return false;
        }

        return curr->isLeaf;
    }

    bool searchPrefix(string str)
    {
        if(this == nullptr)
            return false;

        Trie *curr = this;
        for(int i=0 ; i<SIZE(str) ; i++)
        {
            curr = curr->children[TO_NUM(str[i])];

            if(curr == nullptr)
                return false;
        }

        return (haveChild(curr) && curr->isLeaf);
    }

};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int T=0;
    cin>>T;

    while(T--)
    {
        int N;
        cin>>N;

        vector<string> phones(N);
        Trie trie;

        for(auto &it : phones)
        {
            cin>>it;
            trie.insert(it);
        }

        bool flag=false;
        for(auto &it : phones)
            flag = flag || trie.searchPrefix(it);

        cout<<(flag ? "NO" : "YES")<<"\n";
    }

    return 0;
}

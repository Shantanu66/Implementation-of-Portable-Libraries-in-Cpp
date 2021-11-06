#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

class Trie
{
public:
    bool isterminal;
    vector<Trie *> child;
    Trie()
    {
        child = vector<Trie *>(26);
        isterminal = false;
        for (int i = 0; i < child.size(); i++)
        {
            child[i] = NULL;
        }
    }
    void Insert(string word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (child[word[i] - 'A'] == NULL)
            {
                child[word[i] - 'A'] = new Trie();
            }
            child[word[i] - 'A'];
        }
        isterminal = true;
    }
    bool Search(string word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (child[word[i] - 'A'] == NULL)
            {
                return false;
            }
            child[word[i] - 'A'];
        }
        return isterminal;
    }
};
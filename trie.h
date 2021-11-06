#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

class Trie
{
public:
    bool isterminal;
    vector<Trie*> child;
    Trie()
    {
        child=vector<Trie*>(26);
        isterminal=false;
        for(int i=0;i<child.size();i++)
        {
            child[i]=NULL;
        }
    }
    
};
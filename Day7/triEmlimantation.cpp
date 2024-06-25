#include <iostream>
using namespace std;

class triNode
{
public:
    char data;
    triNode *children[26];
    bool isterminal;
    triNode(char ch)
    {
        data = ch;
        isterminal = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class trie
{
public:
    triNode *root;
    trie()
    {
        root = new triNode('\0');
    }

    void insertUtils(triNode *root, string word)
    {

        if (word.size() == 0)
        {
            root->isterminal = true;
            return;
        }

        // assume that all char will be in cap letter
        int index = word[0] - 'A';
        triNode *child;

        // if peresent

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        { 
            // add new  char 
            child = new triNode(word[0]);
            root->children[index] = child;
        }
        insertUtils(child, word.substr(1));
    }

    void insertInTrie(string word)
    {
        insertUtils(root, word);
    }

    bool finUtils(triNode *root, string word)
    {

        if (word.size() == 0)
        {
            return root->isterminal;
        }

        int index = word[0] - 'A';
        triNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

       return  finUtils(child, word.substr(1));
    }

    bool findword(string word)
    {
        return finUtils(root, word);
    }
};

int main()
{

    trie *t = new trie();

    t->insertInTrie("RAJU");

   cout<<"find word id "<< t->findword("RAJUN");

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    // check if refrence trie is present or not
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    // creating refrence trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // to get the refrence trie
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // setting flag true at the end of word
    void setEnd()
    {
        flag = true;
    }

    // checking if the word is completed or not
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        // initializing dummy node pointing to root initially
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->containKey(word[i]))
            {
                curr->put(word[i], new Node());
            }

            curr = curr->get(word[i]);
        }

        curr->setEnd();
    }

    bool search(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!curr->containKey(word[i]))
            {
                return false;
            }
            curr = curr->get(word[i]);
        }

        return curr->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *curr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!curr->containKey(prefix[i]))
            {
                return false;
            }
            curr = curr->get(prefix[i]);
        }

        return true;
    }
};

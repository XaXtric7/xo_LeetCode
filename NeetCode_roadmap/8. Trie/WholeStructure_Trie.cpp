#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;

        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

    bool deleteHelper(TrieNode *curr, string word, int depth)
    {
        if (curr == nullptr)
            return false;

        // Reached end of word
        if (depth == word.length())
        {

            if (!curr->isEndOfWord)
                return false;

            curr->isEndOfWord = false;

            // Check if node has children
            for (int i = 0; i < 26; i++)
            {
                if (curr->children[i] != nullptr)
                    return false;
            }

            return true;
        }

        int index = word[depth] - 'a';

        if (deleteHelper(curr->children[index], word, depth + 1))
        {

            delete curr->children[index];
            curr->children[index] = nullptr;

            if (curr->isEndOfWord)
                return false;

            for (int i = 0; i < 26; i++)
            {
                if (curr->children[i] != nullptr)
                    return false;
            }

            return true;
        }

        return false;
    }

public:
    Trie()
    {
        root = new TrieNode();
    }

    // INSERT
    void insert(string word)
    {
        TrieNode *curr = root;

        for (char ch : word)
        {
            int index = ch - 'a';

            if (curr->children[index] == nullptr)
            {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }

        curr->isEndOfWord = true;
    }

    // SEARCH
    bool search(string word)
    {
        TrieNode *curr = root;

        for (char ch : word)
        {
            int index = ch - 'a';

            if (curr->children[index] == nullptr)
                return false;

            curr = curr->children[index];
        }

        return curr->isEndOfWord;
    }

    // PREFIX SEARCH
    bool startsWith(string prefix)
    {
        TrieNode *curr = root;

        for (char ch : prefix)
        {
            int index = ch - 'a';

            if (curr->children[index] == nullptr)
                return false;

            curr = curr->children[index];
        }

        return true;
    }

    // DELETE WORD
    void remove(string word)
    {
        deleteHelper(root, word, 0);
    }
};

// Driver code...

int main()
{

    Trie trie;

    trie.insert("cat");
    trie.insert("car");
    trie.insert("care");
    trie.insert("dog");

    cout << trie.search("cat") << endl;  // 1
    cout << trie.search("car") << endl;  // 1
    cout << trie.search("care") << endl; // 1
    cout << trie.search("cow") << endl;  // 0

    trie.remove("car");

    cout << trie.search("car") << endl;  // 0
    cout << trie.search("care") << endl; // 1

    cout << trie.startsWith("ca") << endl; // 1
    cout << trie.startsWith("do") << endl; // 1
    cout << trie.startsWith("xy") << endl; // 0

    return 0;
}
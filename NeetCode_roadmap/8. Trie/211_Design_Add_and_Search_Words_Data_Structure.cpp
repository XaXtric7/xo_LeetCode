class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class WordDictionary
{
private:
    TrieNode *root;

    bool dfs(string &word, int pos, TrieNode *node)
    {
        if (pos == word.length())
        {
            return node->isEnd;
        }

        char ch = word[pos];
        if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->children[i] && dfs(word, pos + 1, node->children[i]))
                {
                    return true;
                }
            }
            return false;
        }

        int index = ch - 'a';

        if (node->children[index] == nullptr)
        {
            return false;
        }

        return dfs(word, pos + 1, node->children[index]);
    }

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *curr = root;

        for (char c : word)
        {
            int index = c - 'a';

            if (curr->children[index] == nullptr)
            {
                curr->children[index] = new TrieNode();
            }

            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool search(string word)
    {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
class TrieNode
{
public:
    TrieNode *children[26];
    string word;

    TrieNode()
    {
        word = "";

        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

class Solution
{
    // insert and search functions...
private:
    TrieNode *root = new TrieNode();

    void insert(string &word)
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
        curr->word = word;
    }

    void dfs(vector<vector<char>> &board, int r, int c, TrieNode *node, vector<string> &ans)
    {
        char ch = board[r][c];

        if (ch == '#')
            return;

        int index = ch - 'a';
        node = node->children[index];

        if (node == nullptr)
        {
            return;
        }

        if (node->word != "")
        {
            ans.push_back(node->word);

            // prevent duplicates...
            node->word = "";
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++)
        {
            int nr = r + delrow[k];
            int nc = c + delcol[k];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols)
            {
                dfs(board, nr, nc, node, ans);
            }
        }
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (string &word : words)
        {
            // building the trie...
            insert(word);
        }
        vector<string> ans;

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
};
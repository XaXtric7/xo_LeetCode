/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
private:
    void preorderSerialize(TreeNode *node, string &newBT)
    {
        if (node == nullptr)
        {
            newBT += "null,";
            return;
        }
        newBT += (to_string(node->val) + ",");
        preorderSerialize(node->left, newBT);
        preorderSerialize(node->right, newBT);
    }

    TreeNode *preorderDeserialize(int &idx, const vector<string> &tokens)
    {
        if (idx >= tokens.size())
            return nullptr;
        string current = tokens[idx++];

        if (current == "null")
        {
            return nullptr;
        }

        TreeNode *newNode = new TreeNode(stoi(current));
        newNode->left = preorderDeserialize(idx, tokens);
        newNode->right = preorderDeserialize(idx, tokens);

        return newNode;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string newBT = "";
        preorderSerialize(root, newBT);
        return newBT;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ','))
        {
            if (!token.empty())
            {
                tokens.push_back(token);
            }
        }
        int idx = 0;
        return preorderDeserialize(idx, tokens);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
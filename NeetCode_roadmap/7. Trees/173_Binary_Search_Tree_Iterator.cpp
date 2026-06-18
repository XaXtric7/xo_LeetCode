/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator
{
    vector<int> values;
    int currIndex;

private:
    void inorderTraversal(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorderTraversal(node->left);
        values.push_back(node->val);
        inorderTraversal(node->right);
    }

public:
    BSTIterator(TreeNode *root)
    {
        currIndex = 0;
        inorderTraversal(root);
    }

    int next()
    {
        return values[currIndex++];
    }

    bool hasNext()
    {
        return currIndex < values.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
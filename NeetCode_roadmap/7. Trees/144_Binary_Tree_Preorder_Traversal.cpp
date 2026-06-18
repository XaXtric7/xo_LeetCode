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
class Solution
{
private:
    void preOrderTraversal(TreeNode *node, vector<int> &values)
    {
        if (node == nullptr)
        {
            return;
        }
        values.push_back(node->val);
        preOrderTraversal(node->left, values);
        preOrderTraversal(node->right, values);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> values;
        preOrderTraversal(root, values);
        return values;
    }
};
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
    void postOrder(TreeNode *node, vector<int> &values)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrder(node->left, values);
        postOrder(node->right, values);
        values.push_back(node->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> values;
        postOrder(root, values);
        return values;
    }
};
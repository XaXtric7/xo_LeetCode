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
    bool inorder(TreeNode *node, long long &prev)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (!inorder(node->left, prev))
            return false;
        if (prev >= node->val)
        {
            return false;
        }
        prev = node->val;
        return inorder(node->right, prev);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        long long prev = LLONG_MIN;
        return inorder(root, prev);
    }
};
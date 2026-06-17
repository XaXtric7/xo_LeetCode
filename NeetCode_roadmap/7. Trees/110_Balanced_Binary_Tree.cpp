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
    int checkBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = checkBalanced(root->left);
        if (leftHeight == -1)
            return -1;

        int rightHeight = checkBalanced(root->right);
        if (rightHeight == -1)
            return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return checkBalanced(root) != -1;
    }
};
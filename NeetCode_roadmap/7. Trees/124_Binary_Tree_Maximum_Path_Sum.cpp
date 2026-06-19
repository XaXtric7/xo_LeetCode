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
    int findMaxSum(TreeNode *node, int &res)
    {
        if (node == nullptr)
        {
            return 0;
        }
        // postOrder = left -> right -> root
        int l = max(0, findMaxSum(node->left, res));
        int r = max(0, findMaxSum(node->right, res));

        res = max(res, l + r + node->val);
        return node->val + max(l, r);
    }

public:
    // using postorder traversal...
    int maxPathSum(TreeNode *root)
    {
        int res = root->val;
        findMaxSum(root, res);
        return res;
    }
};
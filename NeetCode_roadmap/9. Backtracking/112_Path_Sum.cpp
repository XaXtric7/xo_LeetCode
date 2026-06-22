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
    bool dfs(TreeNode *node, int sum, int targetSum)
    {
        // base case...
        if (node == nullptr)
        {
            return false;
        }

        sum += node->val;

        if (node->left == nullptr && node->right == nullptr)
        {
            return sum == targetSum;
        }

        bool leftPath = dfs(node->left, sum, targetSum);
        bool rightPath = dfs(node->right, sum, targetSum);

        return leftPath || rightPath;
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }

        return dfs(root, 0, targetSum);
    }
};
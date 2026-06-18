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
    int findDiameter(TreeNode *node, int &maxDiameter)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int lDepth = findDiameter(node->left, maxDiameter);
        int rDepth = findDiameter(node->right, maxDiameter);

        maxDiameter = max(maxDiameter, lDepth + rDepth);
        return 1 + max(lDepth, rDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxDiameter = 0;
        findDiameter(root, maxDiameter);
        return maxDiameter;
    }
};
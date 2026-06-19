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
    int countGN(TreeNode *node, int prevMax)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int count = 0;

        if (node->val >= prevMax)
        {
            count = 1;
            prevMax = node->val;
        }

        count += countGN(node->left, prevMax);
        count += countGN(node->right, prevMax);
        return count;
    }

public:
    int goodNodes(TreeNode *root)
    {
        return countGN(root, root->val);
    }
};
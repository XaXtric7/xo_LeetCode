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
    bool isSame(TreeNode *node1, TreeNode *node2)
    {
        if (node1 == nullptr && node2 == nullptr)
            return true;
        if (node1 == nullptr || node2 == nullptr)
            return false;

        if (node1->val != node2->val)
            return false;

        return isSame(node1->left, node2->left) && isSame(node1->right, node2->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
        {
            return false;
        }

        return isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
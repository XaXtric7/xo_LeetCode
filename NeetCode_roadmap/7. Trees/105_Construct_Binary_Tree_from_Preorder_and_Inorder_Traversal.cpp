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
    int search(vector<int> &inorder, int &rootVal, int &left, int &right)
    {
        for (int i = left; i <= right; i++)
        {
            if (inorder[i] == rootVal)
            {
                return i;
            }
        }
        return -1;
    }

    TreeNode *buidIT(unordered_map<int, int> &mp, vector<int> &inorder, vector<int> &preorder, int &preIndex, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int rootVal = preorder[preIndex];
        preIndex++;
        TreeNode *root = new TreeNode(rootVal);
        int pivot = search(inorder, rootVal, left, right); // to search the pivot point
        root->left = buidIT(mp, inorder, preorder, preIndex, left, pivot - 1);
        root->right = buidIT(mp, inorder, preorder, preIndex, pivot + 1, right);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int preIndex = 0;
        return buidIT(mp, inorder, preorder, preIndex, 0, inorder.size() - 1);
    }
};
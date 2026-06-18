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
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<int> result;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> currentLevel;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                currentLevel.push_back(curr->val);

                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            int n = currentLevel.size();
            result.push_back(currentLevel[n - 1]);
        }
        return result;
    }
};
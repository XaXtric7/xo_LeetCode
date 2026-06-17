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
class Solution {
private:
    TreeNode* getSuccessor(TreeNode *curr){
        // the smallest in the right subtree
        curr = curr->right;
        while(curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }
        // traverse in the search of the node to delete
        if(root->val < key){
            // if less than the node to delete go right
            root->right = deleteNode(root->right, key);
        }
        else if(root->val > key){
            // if more than the node to delete go left
            root->left = deleteNode(root->left, key);
        }
        else{
            // if node is found but has 0 or 1 child
            if(root->left == nullptr){
                TreeNode *temp = root->right;
                delete root;
                return temp; 
            }
            if(root->right == nullptr){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            //Node has 2 children
            TreeNode* succ = getSuccessor(root);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};
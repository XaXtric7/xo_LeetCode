#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    TreeNode *insert(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            TreeNode *newNode = new TreeNode(val);
            return newNode;
        }

        if (val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    TreeNode *search(TreeNode *root, int key)
    {
        if (root == nullptr || root->val == key)
            return root;

        if (key < root->val)
            return search(root->left, key);

        return search(root->right, key);
    }

    TreeNode *getSuccessor(TreeNode *curr)
    {
        curr = curr->right;

        while (curr != nullptr && curr->left != nullptr)
        {
            curr = curr->left;
        }

        return curr;
    }

    TreeNode *getPredecessor(TreeNode *curr)
    {
        curr = curr->left;

        while (curr != nullptr && curr->right != nullptr)
        {
            curr = curr->right;
        }

        return curr;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (root == nullptr)
            return nullptr;

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {

            // 0 child or right child only
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }

            // left child only
            if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // 2 children
            TreeNode *succ = getSuccessor(root);

            root->val = succ->val;

            root->right =
                deleteNode(root->right, succ->val);
        }

        return root;
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void preorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    int height(TreeNode *root)
    {

        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    TreeNode *root;

    BST()
    {
        root = nullptr;
    }

    void insert(int val)
    {
        root = insert(root, val);
    }

    bool search(int key)
    {
        return search(root, key) != nullptr;
    }

    void deleteValue(int key)
    {
        root = deleteNode(root, key);
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }

    void preorder()
    {
        preorder(root);
        cout << endl;
    }

    void postorder()
    {
        postorder(root);
        cout << endl;
    }

    int height()
    {
        return height(root);
    }

    void levelOrder()
    {

        if (root == nullptr)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            TreeNode *curr = q.front();
            q.pop();

            cout << curr->val << " ";

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        cout << endl;
    }

    void dfsIterative()
    {

        if (root == nullptr)
            return;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {

            TreeNode *curr = st.top();
            st.pop();

            cout << curr->val << " ";

            if (curr->right)
                st.push(curr->right);

            if (curr->left)
                st.push(curr->left);
        }

        cout << endl;
    }

    int getMin()
    {

        TreeNode *curr = root;

        while (curr->left != nullptr)
            curr = curr->left;

        return curr->val;
    }

    int getMax()
    {

        TreeNode *curr = root;

        while (curr->right != nullptr)
            curr = curr->right;

        return curr->val;
    }
};

int main()
{

    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: ";
    tree.inorder();

    cout << "Preorder: ";
    tree.preorder();

    cout << "Postorder: ";
    tree.postorder();

    cout << "Level Order: ";
    tree.levelOrder();

    cout << "DFS: ";
    tree.dfsIterative();

    cout << "Height: "
         << tree.height()
         << endl;

    cout << "Minimum: "
         << tree.getMin()
         << endl;

    cout << "Maximum: "
         << tree.getMax()
         << endl;

    cout << "Search 60: "
         << tree.search(60)
         << endl;

    tree.deleteValue(70);

    cout << "After deleting 70: ";
    tree.inorder();

    return 0;
}
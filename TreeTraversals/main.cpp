#include <vector>
#include <iostream>
#include <stack>
using namespace std;
// Definition for a binary tree node.

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    void preorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    void postorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

class SolutionIterative
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *current_ptr = root;
        while (!s.empty() || current_ptr != nullptr)
        {
            if (current_ptr != nullptr)
            {
                ans.push_back(current_ptr->val);
                s.push(current_ptr);
                current_ptr = current_ptr->left;
            }
            else
            {
                current_ptr = s.top();
                s.pop();
                current_ptr = current_ptr->right;
            }
        }
        return ans;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *current_ptr = root;
        while (!s.empty() || current_ptr != nullptr)
        {
            if (current_ptr != nullptr)
            {
                s.push(current_ptr);
                current_ptr = current_ptr->left;
            }
            else
            {
                current_ptr = s.top();
                s.pop();
                ans.push_back(current_ptr->val);
                current_ptr = current_ptr->right;
            }
        }
        return ans;
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *current_ptr = root;
        TreeNode *previous_ptr = nullptr;
        while (current_ptr != nullptr || !s.empty())
        {
            if (current_ptr != nullptr)
            {
                s.push(current_ptr);
                current_ptr = current_ptr->left;
            }
            else
            {
                TreeNode *parent = s.top();
                if (parent->right != nullptr && parent->right != previous_ptr)
                {
                    current_ptr = parent->right;
                }
                else
                {
                    ans.push_back(parent->val);
                    previous_ptr = parent;
                    s.pop();
                    current_ptr = nullptr;
                }
            }
        }
        return ans;
    }
};

int main()
{
    SolutionIterative sol;
    // Creating a big enough sample binary tree:
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(8);        // Adding node 8
    root->right->right->right = new TreeNode(9); // Adding node 9

    /**
     *          1
     *         / \
     *        4   2
     *       / \ / \
     *      5  6 3  8
     *        /      \
     *       7        9
     */
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);

    vector<int> preResult = sol.preorderTraversal(root);
    vector<int> inResult = sol.inorderTraversal(root);
    vector<int> postResult = sol.postorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : preResult)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "Inorder Traversal: ";
    for (int val : inResult)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "Postorder Traversal: ";
    for (int val : postResult)
    {
        cout << val << " ";
    }
    cout << endl;
    // Clean up memory (not shown here for brevity)
    return 0;
}
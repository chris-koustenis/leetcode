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
        else
        {
            ans.push_back(root->val);
            preorder(root->left, ans);
            preorder(root->right, ans);
        }
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        preorder(root, ans);
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
};

// vector<int> Solution::preorderTraversal(TreeNode *A)
// {
//     stack<TreeNode *> st;
//     TreeNode *node = A;
//     vector<int> v;
//     while (!st.empty() || node != NULL)
//     {
//         if (node != NULL)
//         {
//             v.push_back(node->val);
//             st.push(node);
//             node = node->left;
//         }
//         else
//         {
//             node = st.top();
//             st.pop();
//             node = node->right;
//         }
//     }
//     return v;
// }
int main()
{
    SolutionIterative sol;
    // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = sol.preorderTraversal(root);

    // Print the result
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
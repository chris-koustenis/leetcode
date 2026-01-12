#include <iostream>
#include <vector>
using namespace std;
//
//   Definition for a binary tree node.
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


int main()
{
    Solution sol;
    // Creating a sample binary tree:
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = sol.preorderTraversal(root);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
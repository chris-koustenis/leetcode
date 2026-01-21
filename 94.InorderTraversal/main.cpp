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
    void inorder(TreeNode* root, vector<int> &ans){
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode *root)
    {   
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

class SolutionIterative
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<int> s;
        


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

    vector<int> result = sol.inorderTraversal(root);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (not shown here for brevity)
    return 0;
}
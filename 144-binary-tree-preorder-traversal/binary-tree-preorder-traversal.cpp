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
public:
    void fPreorderTraversal(TreeNode* root, vector<int>& ans){
        if (root==nullptr) return;
        ans.push_back(root->val);
        fPreorderTraversal(root->left, ans);
        fPreorderTraversal(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        fPreorderTraversal(root, ans);
        return ans;
    }
};
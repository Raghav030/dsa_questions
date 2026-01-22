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
    int fbalanced(TreeNode* root, bool& ans){
        if (root==nullptr) return 0;
        int left_height= fbalanced(root->left, ans);
        int right_height= fbalanced(root->right, ans);
        // bool cur= true;
        if (abs(left_height- right_height)>1) ans= false;
        // cout<< ans;
        // if (cur== false) ans= cur;
        return max(left_height, right_height)+1; 
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        fbalanced(root, ans);
        return ans;
    }
};
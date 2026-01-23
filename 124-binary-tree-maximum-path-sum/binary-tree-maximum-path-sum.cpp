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
    int fpathsum(TreeNode* root, int& ans){
        if (root==nullptr) return -1e9;
        int left_path= fpathsum(root->left, ans);
        int right_path= fpathsum(root->right, ans);
        int total_path_sum= left_path+right_path+ root-> val;
        int cur_val= root->val;
        int cur_max_path= max(left_path+max(cur_val,0), right_path+ max(cur_val, 0));
        cur_max_path= max(cur_max_path, total_path_sum);
        cur_max_path= max(cur_max_path, root->val);
        ans= max(cur_max_path, ans);
        int branch_path= max(max(left_path, right_path)+ root->val, root->val);
        return branch_path;
    }
    int maxPathSum(TreeNode* root) {
        int ans= -1e9;
        fpathsum(root, ans);
        return ans;
    }
};
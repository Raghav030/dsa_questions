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
    void fdepth(TreeNode* root, int cur_height, int& ans){
        if(root==nullptr) return;
        fdepth(root->left, cur_height+1, ans);
        fdepth(root->right, cur_height+1, ans);
        ans = max(cur_height, ans);
    }
    int maxDepth(TreeNode* root) {
        if (root==nullptr) return 0;
        int ans=1;
        fdepth(root, 1, ans);
        return ans;
    }
};
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q; 
        if (root==nullptr) return {};
        q.push(root);
        vector<int> ans;
        while (!q.empty()){
            int n= q.size();
            for (int i=0; i<n; i++){
                TreeNode* cur_node= q.front();
                if (cur_node->left) q.push(cur_node->left);
                if (cur_node->right) q.push(cur_node-> right);
                if (i==n-1) ans.push_back(cur_node->val);
                q.pop();
            }
        }
        return ans;
    }
};
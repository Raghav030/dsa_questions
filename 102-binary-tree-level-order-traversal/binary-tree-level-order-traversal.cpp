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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root==nullptr) return {};
        q.push(root);
        vector<vector<int>> ans;
        int n=1, next_length=0;
        while (n>0){
            vector<int> cur;
            next_length=0;
            for (int i=0; i<n; i++){
                TreeNode* cur_node=q.front();
                if (cur_node->left) {
                    q.push(cur_node->left);
                    next_length+=1;
                }
                if (cur_node->right){
                    q.push(cur_node->right);
                    next_length+=1;
                }
                cur.push_back(cur_node->val);
                q.pop();
            }
            ans.push_back(cur);
            n= next_length;
        } 
        return ans;
    }
};
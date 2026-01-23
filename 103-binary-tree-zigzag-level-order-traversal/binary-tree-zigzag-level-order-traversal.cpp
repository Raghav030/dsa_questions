/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left; 
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root==nullptr) return ans;
        q.push(root);
        int flag=0;
        // vector<int> cur
        while (!q.empty()){
            int n=q.size();
            vector<int> cur;
            for (int i=0; i<n; i++){
                TreeNode* cur_node= q.front();
                cur.push_back(cur_node ->val);
                q.pop();
                if (cur_node->left) q.push(cur_node->left);
                if (cur_node->right) q.push(cur_node->right);
            }
            if (flag==1){
                for (int i=0;i<n/2; i++){
                    swap(cur[i], cur[n-i-1]);
                }
            }
            ans.push_back(cur);
            flag= 1-flag;
        }
        return ans;
    }
};
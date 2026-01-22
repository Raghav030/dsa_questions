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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if (root==nullptr) return {};
        st.push(root);
        vector<int> ans;
        while (!st.empty()){
            // for (int )
            TreeNode* cur_node= st.top();
            ans.push_back(cur_node->val);
            st.pop();
            if (cur_node->right){
                st.push(cur_node->right);
            }
            if (cur_node-> left) st.push(cur_node->left);
        }
        return ans;
    }
};
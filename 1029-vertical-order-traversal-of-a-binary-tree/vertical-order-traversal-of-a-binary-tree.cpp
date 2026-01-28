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
    void fverticalOrderTraversal(TreeNode* root, map<int, map<int,multiset<int>>>& mpp, int vertical, int level){
        if (root==nullptr) return;
        int num= root-> val;
        // if (mpp.find(vertical) != mpp.end()){
            // map<int, multiset<int>> temp_mpp= mpp[vertical];
        //     if (temp_mpp.find(level) != temp_mpp.end()) temp_mpp[level].insert(root->val);
        //     else {
        //         temp_mpp[level]={root->val};
        //         mpp[vertical]= temp_mpp;
        //     }
        mpp[vertical][level].insert(root->val);
        // }
        // else mpp[vertical]= {level, {num}};
        if (root->left) fverticalOrderTraversal(root->left, mpp, vertical-1, level+1);
        if (root-> right) fverticalOrderTraversal(root->right, mpp, vertical+1, level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mpp;
        vector<vector<int>> ans;
        fverticalOrderTraversal(root, mpp, 0, 0);
        for (auto vertical: mpp){
            vector<int> cur;
            for (auto level: vertical.second){
                // while (level.second.size()>0) {
                    // int cur_num= *level.second.begin();
                    // cur.push_back(cur_num);
                    // level.second.erase(cur_num);
                cur.insert(cur.end(), level.second.begin(), level.second.end());
                // } 
            }
            ans.push_back(cur);
        }
        return ans;

    }
};
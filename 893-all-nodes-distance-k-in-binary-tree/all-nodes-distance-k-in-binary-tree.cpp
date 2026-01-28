/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fnodes(TreeNode* root, TreeNode* target, int& k, int& flag, vector<int>& ans){
        if (root==nullptr) return;
        if (root== target and flag==0){
            flag=1;
            if (k==0) {
                ans.push_back(root->val);
                return;
            }
            // k-=1;
            fnodes(root->right, target, k, flag, ans);
            fnodes(root->left, target, k, flag, ans);
            // k+=1;
        }
        else if (flag==1){
            k-=1;
            if (k==0){

                ans.push_back(root->val);
                k+=1;
                return;
            }
            // k-=1;
            fnodes(root->left, target, k, flag, ans);
            fnodes(root->right, target, k, flag, ans);
            k+=1;
        }
        else{
            fnodes(root->left, target, k, flag, ans);
            if (flag==1){
                k-=1;
                if (k==0){
                    ans.push_back(root->val);
                    return;
                }
                // k-=1;
                fnodes(root->right, target, k, flag, ans);
                // k+=1;
            }
            else{
                fnodes(root->right, target, k, flag, ans);
                if (flag==1){
                    k-=1;
                    if (k==0) {
                        ans.push_back(root->val);
                        return;
                    }
                    // k-=1;
                    fnodes(root->left, target, k, flag, ans);
                    // k+=1;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        int flag=0;
        fnodes(root, target, k, flag, ans);
        return ans;
    }
};
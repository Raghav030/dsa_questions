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
    void flcs(TreeNode* root, TreeNode* p, TreeNode* q, int& flag, TreeNode* &cur_lcs){
        if (root==nullptr) return ;
        if (flag==0){
            if (root==p or root==q){
                cur_lcs= root;
                flag= (root==p)?1:2;
            }
            flcs(root->left, p, q, flag, cur_lcs);
            if (flag==1 or flag==2){
                cur_lcs=root;
                cout<<root->val<<' ';
                flcs(root->right, p, q, flag, cur_lcs);
            }
            if (flag==3) return;
            if (flag==0) flcs(root->right, p, q, flag, cur_lcs);
        }
        if (flag==1){
            if (root== q) {
                flag=3;
                return;
            }
            flcs(root->left, p, q, flag, cur_lcs);
            flcs(root->right, p, q, flag, cur_lcs);
        }
        if (flag==2 ){
            if (root==p){
                flag=3;
                return;
            }
            flcs(root->left, p, q, flag, cur_lcs);
            flcs(root->right, p, q, flag, cur_lcs);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur_lcs= root;
        int flag=0;
        flcs(root, p, q, flag, cur_lcs);
        return cur_lcs;
    }
};
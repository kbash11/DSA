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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        TreeNode* left=NULL;
        if(root->left){
            left=searchBST(root->left,val);
        }
        
        TreeNode* right=NULL;
        if(root->right){
            right=searchBST(root->right,val);
        }
        return left!=NULL ? left : right;
    }
};
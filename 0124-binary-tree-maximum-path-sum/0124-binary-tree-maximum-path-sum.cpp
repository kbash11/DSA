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
    int solve(TreeNode* root,int& maxi){
        
        if(!root){
            return 0;
        }

        int left=solve(root->left,maxi);;
        int right=solve(root->right,maxi);
        
        maxi=max(maxi,root->val+left+right);
        return max(0,root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        
        int maxi=INT_MIN;
        int x= solve(root,maxi);
        return maxi;
    }
};
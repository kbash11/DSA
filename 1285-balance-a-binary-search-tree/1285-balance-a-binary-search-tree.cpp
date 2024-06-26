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
    void solve(TreeNode* root,vector<int>& arr){
        if(root==NULL){
            return;
        }
        solve(root->left,arr);
        arr.push_back(root->val);
        solve(root->right,arr);
    }
    TreeNode* helper(int i,int j,vector<int> arr){
        if(i>j){
            return NULL;
        }
        int mid=i+(j-i)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=helper(i,mid-1,arr);
        root->right=helper(mid+1,j,arr);
        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        solve(root,arr);
        return helper(0,arr.size()-1,arr);
    }
};
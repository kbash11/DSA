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
    TreeNode* solve(vector<int>& post,vector<int>& in,map<int,int>& m, int inStart,int inEnd, int postStart, int postEnd){
        if(postStart>postEnd || inStart>inEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(post[postEnd]);
        int inRoot=m[root->val];
        int numLeft=inRoot-inStart;
        root->left=solve(post,in,m,inStart,inRoot-1,postStart,postStart+numLeft-1);
        root->right=solve(post,in,m,inRoot+1,inEnd,postStart+numLeft,postEnd-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(postorder,inorder,m,0,inorder.size()-1,0,postorder.size()-1);
    }
};
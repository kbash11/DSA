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
    TreeNode* solve(vector<int>& pre,vector<int>& in,map<int,int>& m, int inStart,int inEnd, int preStart, int preEnd){
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(pre[preStart]);
        int inRoot=m[root->val];
        int numLeft=inRoot-inStart;
        root->left=solve(pre,in,m,inStart,inRoot-1,preStart+1,preStart+numLeft);
        root->right=solve(pre,in,m,inRoot+1,inEnd,preStart+numLeft+1,preEnd);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(preorder,inorder,m,0,inorder.size()-1,0,preorder.size()-1);
    }
};
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,  long long>> q;
        q.push({root, 0});
        long long maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            long long left = q.front().second;
            long long right = q.back().second;
            maxWidth = max(maxWidth, right - left + 1);

            for (int i = 0; i < size; i++) {
                auto [node, level] = q.front();
                q.pop();
                long long curIndex = level - left;  // Normalize the index to prevent overflow

                if (node->left) {
                    q.push({node->left, 2 * curIndex + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * curIndex + 2});
                }
            }
        }

        return maxWidth;
    }
};
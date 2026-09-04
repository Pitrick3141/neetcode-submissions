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
    int nodeLeft_ = -1;
public:
    int kthSmallest(TreeNode* root, int k) {
        if(nodeLeft_ == -1) nodeLeft_ = k;
        if(!root) return -1;
        int searched = kthSmallest(root->left, k);
        if(nodeLeft_ == 0) return searched;
        nodeLeft_ --;
        if(nodeLeft_ == 0) return root->val;
        return kthSmallest(root->right, k);
    }
};

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
    bool isValidBSTHelper(TreeNode* root, int lt, int gt) {
        if(!root) return true;
        if(root->val >= lt || root -> val <= gt) return false;
        return isValidBSTHelper(root -> left, root->val, gt) && isValidBSTHelper(root->right, lt, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, 1000000010, -1000000010);
    }
};

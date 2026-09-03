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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int depth = 0;
        queue<pair<int,TreeNode*>> q;
        q.push({0, root});
        while(!q.empty()) {
            TreeNode* current = q.front().second;
            int currentDepth = q.front().first;
            q.pop();
            if(!current) continue;
            if(currentDepth >= ans.size()) ans.push_back({});
            ans[currentDepth].push_back(current -> val);
            q.push({currentDepth + 1, current -> left});
            q.push({currentDepth + 1, current -> right});
        }
        return ans;
    }
};

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr) return ans;
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty())
        {
            int n = que.size();
            for(int i =0; i<n; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if(i == n-1)
                {
                    ans.push_back(node->val);
                }
                if(node->left != nullptr) 
                {
                    que.push(node->left);
                }
                if(node->right != nullptr)
                {
                    que.push(node->right);
                }
            }
        }
        return ans;
    }
};
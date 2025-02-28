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
using ll = unsigned long long;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode* , ll>>que;
        que.push({root, 1});
        int maxWidth = 1;

        while(!que.empty())
        {
            int n= que.size();
            ll li , ri;
            for(int i=0; i<n; i++)
            {
                auto temp = que.front();
                que.pop();
                if(i ==0) li = temp.second;
                if(i == n-1) ri = temp.second;
                TreeNode* node = temp.first;
                if(node ->left != nullptr) que.push({node->left, 2*temp.second });
                if(node ->right != nullptr) que.push({node->right, 2*temp.second+1});
            }
            maxWidth = max(maxWidth, (int)(ri-li +1));
        }

        return maxWidth;
    }
};
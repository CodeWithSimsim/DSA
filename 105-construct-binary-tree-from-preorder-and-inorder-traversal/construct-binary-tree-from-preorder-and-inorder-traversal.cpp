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
    TreeNode* tree(vector<int>&preorder, int spre, int epre, vector<int>&inorder, int sin, int ein, unordered_map<int, int>& mp)
    {
        if(spre > epre || sin > ein) return nullptr;
        TreeNode* node = new TreeNode(preorder[spre]);
        
        int ind = mp[node->val];
        int cnt = ind - sin;

        node->left = tree(preorder, spre+1, spre+cnt, inorder, sin, ind-1, mp);
        node->right = tree(preorder, spre+cnt+1, epre, inorder, ind+1, ein, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return nullptr;

        unordered_map<int, int>mp;
        for(int i=0; i<n; i++)
        {
            mp[inorder[i]] = i;
        }
        TreeNode* root = tree(preorder, 0, n-1, inorder, 0, n-1, mp);
        return root;
        
    }
};

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

    TreeNode* tree(vector<int>& postorder, int spost, int epost, vector<int>& inorder, int sin, int ein, unordered_map<int, int>& mp)
    {
        if(spost > epost || sin > ein) return nullptr;
        TreeNode* node = new TreeNode(postorder[epost]);

        int ind = mp[node->val];
        int cnt = ein - ind;
        node->right = tree(postorder, epost-cnt, epost-1, inorder, ind+1, ein, mp);
        node->left = tree(postorder, spost, epost-cnt-1, inorder, sin, ind-1, mp);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0) return nullptr;

        unordered_map<int, int>mp;
        for(int i =0; i<n; i++)
        {
            mp[inorder[i]] = i;
        }

        TreeNode* root = tree(postorder, 0, n-1, inorder, 0, n-1, mp);
        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp, unordered_map<TreeNode*, int>& vis)
    {
        if(root == nullptr) return;
        vis[root] =0;
        if(root->left != nullptr) 
        {
            mp[root->left] = root;
        }
        if(root ->right != nullptr)
        {
            mp[root->right] = root;
        }
        inorder(root->left, mp, vis);
        inorder(root->right, mp, vis);
    }

    void kthnode(TreeNode* target, int k, unordered_map<TreeNode* , TreeNode*>&mp, unordered_map<TreeNode*, int>& vis, vector<int>& ans)
    {
        if(target == nullptr || k < 0) return;
        if(k ==0) 
        {
            ans.push_back(target->val);
            vis[target] =1;
            return;
        }
        vis[target] =1;
        if(target->left != nullptr && vis[target->left] == 0)
        {
            kthnode(target->left, k-1, mp, vis, ans);
        }
        if(target->right != nullptr && vis[target->right]== 0)
        {
            kthnode(target->right, k-1, mp, vis, ans);
        }
        if(mp.find(target) != mp.end() && vis[mp[target]] == 0)
        {
            kthnode(mp[target], k-1, mp, vis, ans);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root == nullptr) return ans;
        unordered_map<TreeNode* , TreeNode*>mp;
        unordered_map<TreeNode*, int>vis;
        inorder(root, mp, vis);
    
        kthnode(target, k, mp, vis, ans);
        return ans;
    }
};
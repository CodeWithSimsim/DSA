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
    int leftHeight(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return 1+leftHeight(root->left);
    }
    int rightHeight(TreeNode* root)
    {
        if(root == nullptr) return 0;
        return 1+rightHeight(root->right);
    }

    int totalNode(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (pow(2, lh) -1);
        return 1+ totalNode(root->left) + totalNode(root->right);
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int tnode = totalNode(root);
        return tnode;
    }
};
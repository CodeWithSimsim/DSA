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
    TreeNode* leftMostRight(TreeNode* node)
    {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    TreeNode* helper(TreeNode* root)
    {
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;

        TreeNode* leftRight = leftMostRight(root->left);
        leftRight->right = root->right;
        return root->left; // Return new root correctly
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val == key) {
            return helper(root); // Handle root deletion properly
        }

        TreeNode* cur = root;
        while (cur != nullptr) {
            if (cur->val > key) {
                if (cur->left != nullptr && cur->left->val == key) {
                    cur->left = helper(cur->left);
                    break;
                } else {
                    cur = cur->left;
                }
            } else {
                if (cur->right != nullptr && cur->right->val == key) {
                    cur->right = helper(cur->right);
                    break;
                } else {
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};

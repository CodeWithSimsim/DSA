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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return nullptr;

        unordered_map<int, int> mp;  // To store inorder indices for quick lookup
        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = new TreeNode(preorder[0]); // First node is root
        stack<TreeNode*> st;
        st.push(root);

        for(int i = 1; i < n; i++) {
            TreeNode* node = new TreeNode(preorder[i]);
            TreeNode* parent = st.top();
            
            // Left child case (if the index of new node is smaller in inorder)
            if(mp[preorder[i]] < mp[parent->val]) {
                parent->left = node;
            } 
            // Right child case
            else {
                TreeNode* lastPopped = nullptr;
                while(!st.empty() && mp[preorder[i]] > mp[st.top()->val]) {
                    lastPopped = st.top();
                    st.pop();
                }
                lastPopped->right = node;
            }

            // Push current node to stack
            st.push(node);
        }

        return root;
    }
};

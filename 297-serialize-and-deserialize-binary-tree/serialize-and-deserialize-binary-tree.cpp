/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        if(root == nullptr) return "#";
        stringstream ss;
        ss << root->val << ","<< serialize(root->left)<<"," << serialize(root->right);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* dhelper(stringstream &ss)
    {
        string str;
        getline(ss, str, ',');
        if(str == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(str));
        node->left = dhelper(ss);
        node->right = dhelper(ss);
        return node;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return dhelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
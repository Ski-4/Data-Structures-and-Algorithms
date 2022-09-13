// Link to problem - https://leetcode.com/problems/binary-tree-pruning/solution/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* node) {
        if(!node) return NULL;
        
        node->left = pruneTree(node->left);
        node->right = pruneTree(node->right);
        
        if(!node->left && !node->right && node->val==0) return NULL;
        
        return node;
    }
};
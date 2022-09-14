// Link to problem - https://www.interviewbit.com/problems/next-greater-number-bst/

TreeNode* Solution::getSuccessor(TreeNode* node, int x) {
    if(!node) return NULL;
    if(node->val>x) {
        TreeNode* result = getSuccessor(node->left,x);
        if(result) return result;
        return node;
    }else if(node->val<=x) {
        TreeNode* result = getSuccessor(node->right,x);
        return result;
    }
}
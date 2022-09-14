// Link to problem - https://leetcode.com/problems/construct-string-from-binary-tree/

class Solution {
public:
    string tree2str(TreeNode* node) {
        if(!node) return "";
        
        string ans = to_string(node->val);
        string left = tree2str(node->left);
        string right = tree2str(node->right);
        
        if(left.length()>0 || right.length()>0)
            ans+="("+left+")";
        
        if(right.length()!=0)
            ans+="("+right+")";
        
        return ans;
    }
};
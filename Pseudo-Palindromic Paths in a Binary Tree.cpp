// Link to problem - https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

class Solution{
public:
  int pseudoPalindromicPaths(TreeNode *root, int count = 0){
      
    if (!root)
      return 0;
    count ^= 1 << root->val;
    
    int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
    if (!root->left && !root->right && (count & (count - 1)) == 0)
      res++;
    return res;
    }
};
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
    bool helper(TreeNode* root, int& targetSum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val)
                return true;
            else
                return false;
        }
        targetSum -= root->val;
        bool ans = (root->left?helper(root->left, targetSum):false) || (root->right?helper(root->right, targetSum) : false);
        targetSum += root->val;
        return ans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) { return root?helper(root, targetSum):false; }
};
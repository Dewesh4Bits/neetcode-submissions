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

int util_checkHeightBalance(TreeNode *root, bool &isBalancedTree){
    if(root==NULL)
        return 0; 
    if(isBalancedTree==false)
        return -1; 
    
    int leftHeight = util_checkHeightBalance(root->left, isBalancedTree);
    int rightHeight = util_checkHeightBalance(root->right, isBalancedTree);
    if(abs(leftHeight - rightHeight) > 1){
        isBalancedTree = false; 
        return -1; 
    }

    return max(leftHeight, rightHeight) + 1; 
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool isBalancedTree = true;   
        util_checkHeightBalance(root, isBalancedTree)  ; 
        return isBalancedTree;
    }
};

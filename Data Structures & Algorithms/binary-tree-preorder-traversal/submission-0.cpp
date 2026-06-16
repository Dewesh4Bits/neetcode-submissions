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

void preOrder(TreeNode *node, vector<int> &val){
    if(node==NULL)
        return; 
    val.push_back(node->val); 
    preOrder(node->left, val);
    preOrder(node->right, val);
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> sol;
        preOrder(root, sol); 
        return sol;         
    }
};
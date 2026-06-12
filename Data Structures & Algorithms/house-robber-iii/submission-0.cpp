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

unordered_map<TreeNode  *, vector<int> > potentialMoney; 
class Solution {

    int util(TreeNode *node, bool flag){

        int solution = -404; 
        if(node == NULL){
            solution = 0; 
        }
        else if(potentialMoney.find(node)!=potentialMoney.end() && potentialMoney[node][flag] != -1){
            solution =  potentialMoney[node][flag];
        }
        else{
            vector<int> v(2, -1); 
            if(potentialMoney.find(node)==potentialMoney.end())
                potentialMoney[node] = v; 

            if(flag==false){
                int tempMoney = util(node->left, true) + util(node->right, true);
                solution = potentialMoney[node][flag] = tempMoney; 
            }
            else{
                potentialMoney[node][0] = util(node->left, true) + util(node->right, true);
                potentialMoney[node][1] = util(node->left, false) + util(node->right, false) + node->val;
                solution = (potentialMoney[node][0] > potentialMoney[node][1] ) ? potentialMoney[node][0] : potentialMoney[node][1] ;
            }
        }
        cout<<"Nodeval-> "<< ((node==NULL) ? -404 : node->val) << " flag=" << flag<< "  solution="<<solution<<endl;
        return solution; 
    } 
public:
    int rob(TreeNode* root) {
        int tempSol01 =  util(root, true);
        return tempSol01;        
    }
};
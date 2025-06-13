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
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        int a = 0,b = 0,c = 0,d = 0;
        if(root -> val % 2 == 0){
            if(root -> left){
                if(root -> left -> left){
                    a = root -> left -> left -> val;
                }
                if(root -> left -> right){
                    b = root -> left -> right -> val;
                }
            }
            if(root -> right){
                if(root -> right -> left){
                    c = root -> right -> left -> val;
                }
                if(root -> right -> right){
                    d = root -> right -> right -> val;
                }
            }
        }
        return a + b + c + d + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
    }
};
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
    int sumNumbers(TreeNode* root, int initVal = 0) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr){
            return initVal + root->val;
        }
        int sum = 0;
        sum += sumNumbers(root->left, (initVal+root->val)*10) + sumNumbers(root->right, (initVal+root->val)*10);

        return sum;
    }
};

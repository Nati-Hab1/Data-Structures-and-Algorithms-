#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    std::pmr::unordered_map<TreeNode*,TreeNode*> parent;
    void preorder(TreeNode* current,TreeNode* par){
        if(!current)   return;

        parent[current] = par;
        preorder(current->left,current);
        preorder(current->right,current);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        preorder(root,NULL);

        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;

        while(!q.empty() and k){
            k-=1;
            int size = q.size();
            for(int i=0;i<size;++i){
                TreeNode* current = q.front();
                q.pop();
                visited.insert(current);

                if(!visited.count(current->left) and current->left)   q.push(current->left);
                if(!visited.count(current->right) and current->right)  q.push(current->right);
                if(!visited.count(parent[current]) and parent[current]) q.push(parent[current]);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            ans.push_back(current->val);
        }
        return ans;
    }
};
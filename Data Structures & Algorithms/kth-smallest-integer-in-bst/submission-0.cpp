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
    int ans;
    void findK(TreeNode* root, int &k){
    if(root==NULL || k==0) return;
    findK(root->left,k);
    k--;
    if(k==0){
        ans=root->val;
        return;
    }
    findK(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        ans=0;
        findK(root,k);
        return ans;
    }
};

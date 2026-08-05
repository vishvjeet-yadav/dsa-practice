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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l=0,r=0;
        if(root->left!=NULL) l=1+height(root->left);
        if(root->right!=NULL) r=1+height(root->right);
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int l=0,r=0;
        if(root->left!=NULL) l=1+height(root->left);
        if(root->right!=NULL) r=1+height(root->right);
        return abs(l-r)<2 && isBalanced(root->left) && isBalanced(root->right);
    }
};

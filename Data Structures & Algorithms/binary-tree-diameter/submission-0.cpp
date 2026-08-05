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
    int maxDiameter(TreeNode* root, int &maxx){
        if(root==NULL) return 0;
        int left=0,right=0;
        if(root->left!=NULL) 
           left=1+maxDiameter(root->left,maxx);
        if(root->right!=NULL)
            right=1+maxDiameter(root->right,maxx);
        maxx=max(maxx, left+right);
        // cout<<"For:"<<root->val<<" left:"<<left<<" right:"<<right<<" maxx:"<<maxx<<endl;
        return max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxx=0;
        maxx= max(maxx,maxDiameter(root,maxx));
        return maxx;
    }
};

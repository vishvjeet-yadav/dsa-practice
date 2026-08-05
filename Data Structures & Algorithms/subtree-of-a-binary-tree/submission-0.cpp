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
    bool ans;

    bool checkSub(TreeNode* root, TreeNode* sub){
        if(root==NULL || sub==NULL) return sub==root;
        // cout<<"Check root val->"<<root->val<<" sub-val->"<<sub->val<<endl;
        if(sub==NULL || root->val != sub->val) return false;
        return checkSub(root->left, sub->left) && checkSub(root->right,sub->right);
    }

    void traverse(TreeNode* root, TreeNode* sub){
        if(root==NULL) return;
        // cout<<"Traverse:"<<root->val<<" sub:"<<sub->val<<endl;
        if(root->val==sub->val){
            // cout<<"Checking for :"<<root->val<<endl;
            ans|=checkSub(root,sub);
        }
        traverse(root->left,sub);
        traverse(root->right,sub);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ans=false;
        traverse(root,subRoot);
        return ans;
    }
};

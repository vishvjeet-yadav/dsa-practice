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

    bool checkBST(TreeNode* root, int min, int max){
        if(!root) return true;
        // cout<<"Checking "<<root->val<<" min : "<<min<<" max: "<<max<<endl;
        bool ans=true;
        if(root->val >= max || root->val <= min) ans=false;
        ans&=checkBST(root->left,min,root->val);
        ans&=checkBST(root->right,root->val,max);
        // cout<<"For "<<root->val<<" returning : "<<ans<<endl;
        return ans;
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root,INT_MIN,INT_MAX);
    }
};

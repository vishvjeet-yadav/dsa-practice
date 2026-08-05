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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int lvl=0;
        vector<int> arr;
        while(q.size()>1){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL){
                cout<<"NULL"<<endl;
                lvl++;
                ans.push_back(arr);
                arr.clear();
                q.push(NULL);
            }else{
                cout<<"val->"<<node->val<<endl;
                arr.push_back(node->val);
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
        }
        ans.push_back(arr);
        return ans;
    }
};

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
class Solution1 {
    private:
void helper(TreeNode* root,vector<int> &res)
       { 
        if(root==NULL)
        return;   
        else
       { 
        res.push_back(root->val);
        helper(root->left,res);
        helper(root->right,res);}
        }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        helper(root,res);
        return res;
    }
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;
        TreeNode *curr;
        st.push(root);
        curr=root;
        while(!st.empty()){
            curr=st.top();st.pop();
            if(curr!=NULL)
           {res.push_back(curr->val);
            st.push(curr->right);
            st.push(curr->left);}
        }
        return res;
    }
};

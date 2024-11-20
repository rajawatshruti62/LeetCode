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
       { helper(root->left,res);
        res.push_back(root->val);
        helper(root->right,res);}
        }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        helper(root,res);
        return res;
    }
};
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>res;
        TreeNode *curr; curr=root;
        while(curr!=NULL || !st.empty())
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            res.push_back(curr->val);
            curr=curr->right;
        }
        return res;
    }
};
class Solution {
private:
    TreeNode* right_most(TreeNode*leftmost,TreeNode*curr){
        while(leftmost->right!=NULL && leftmost->right!=curr){
            leftmost=leftmost->right;
        }
        return leftmost;
    }
    vector<int>morristraversal(TreeNode* root){
        TreeNode* curr=root,*leftnode,*rightmost;
        vector<int>ans;
        while(curr!=NULL)
        {
            leftnode=curr->left;
            if(leftnode==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                rightmost=right_most(leftnode,curr);
                if(rightmost->right==NULL){
                rightmost->right=curr;
                curr=curr->left;
                }
                else
                {
                    rightmost->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        return morristraversal(root);
    }
};

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
TreeNode* preorderTraversal(int& i,int n,int lower,int upper,vector<int>&preorder){
if(i>=n || preorder[i]<lower || preorder[i]>upper){
    return NULL;
}
TreeNode* temp=new TreeNode(preorder[i++]);
temp->left=preorderTraversal(i,n,lower,temp->val,preorder);
temp->right=preorderTraversal(i,n,temp->val,upper,preorder);
return temp;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int lower=INT_MIN;
      int upper=INT_MAX;
      int i=0;
      int n= preorder.size();
      return preorderTraversal(i,n,lower,upper,preorder);
    }
};
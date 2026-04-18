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
int search(vector<int>&inorder,int value,int left,int right){
    for(int i=left;i<=right;i++){
        if(inorder[i]==value){
            return i;
        }
    }
    return -1;
}
TreeNode* helper(vector<int>& inorder,vector<int>& postorder,int& postIdx,int left,int right){
if(left>right){
    return NULL;
}
TreeNode* root=new TreeNode(postorder[postIdx]);
postIdx--;
int inIdx=search(inorder,root->val,left,right);
root->right=helper(inorder,postorder,postIdx,inIdx+1,right);
root->left=helper(inorder,postorder,postIdx,left,inIdx-1);

return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
       int postIdx=n-1;
     return  helper(inorder,postorder,postIdx,0,n-1) ;
    }
};
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
void path(TreeNode* root,bool wentLeft,int countPath,int &ans){
if(root==NULL){
    return ;
}
ans=max(ans,countPath);
if(root->left){
    if(wentLeft==false){
     path(root->left,true,countPath+1,ans);   
    }
    else{
      path(root->left,true,1,ans);    
    }
}
if(root->right){
    if(wentLeft==true){
     path(root->right,false,countPath+1,ans);   
    }
    else{
      path(root->right,false,1,ans);    
    }
}


}
    int longestZigZag(TreeNode* root) {
        int ans=0;

        if(root->left){
path(root->left,true,1,ans);
        }
        if(root->right){
path(root->right,false,1,ans);
        }
        return ans;
    }
};
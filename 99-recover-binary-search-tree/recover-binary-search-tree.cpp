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
void update(TreeNode* root,vector<int>&arr,int& i,int n){
if(i>=n){
        return ;
    }
    if(root==NULL){
        return ;
    }
    update(root->left,arr,i,n);
    if(root->val!=arr[i]){
        root->val=arr[i];
    }
    i++;
    update(root->right,arr,i,n);
}
void inorder(TreeNode* root, vector<int>&arr){
    if(root==NULL){
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root->val);
     inorder(root->right,arr);

}
    void recoverTree(TreeNode* root) {
      vector<int>arr;
inorder(root,arr);
int n=arr.size();
int i=0;
sort(arr.begin(),arr.end());
update(root,arr,i,n);

    }
};
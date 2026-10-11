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
 void invertTree(TreeNode* root, int i,int j){
while(i<j){

}
}
    TreeNode* reverseOddLevels(TreeNode* root) {
       queue<TreeNode*>q;
       q.push(root);
     
       int level=0;
       while(!q.empty()){
        int size=q.size();
          vector<TreeNode*>ans;
        while(size--){
          TreeNode* temp=q.front();
          ans.push_back(temp);
          q.pop();
          if(temp->left){
            q.push(temp->left);
          } 
          if(temp->right){
            q.push(temp->right);
          } 
        }
        if(level%2==1){
            int i=0;
            int j=ans.size()-1;
            while(i<j){
                swap(ans[i]->val,ans[j]->val);
                i++;
                j--;
            }
        }
        
        level++;

       } 
       return root;
    }
};
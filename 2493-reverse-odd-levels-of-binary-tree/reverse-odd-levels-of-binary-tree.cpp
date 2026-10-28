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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            vector<TreeNode*>lev;
            int size=q.size();
            while(size--){
              TreeNode* temp=q.front();
              lev.push_back(temp);
              q.pop();
              if(temp->left){
                q.push(temp->left);
              }  
              if(temp->right){
                q.push(temp->right);
              }
            }
            level++;
            if(level%2==0){
                int i=0;
                int j=lev.size()-1;
                while(i<j){
                    swap(lev[i]->val,lev[j]->val);
                    i++;
                    j--;
                }
            }
        }
        return root;
    }
};
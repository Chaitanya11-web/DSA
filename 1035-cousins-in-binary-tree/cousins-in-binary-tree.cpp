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
bool parent(TreeNode* root, int x, int y){
if(root==NULL){
    return false;
}
if(root->left!=NULL && root->right!=NULL){
    if(root->left->val==x && root->right->val==y){
        return true;
    }
     else if(root->left->val==y && root->right->val==x){
        return true;
    }
}
return parent(root->left,x,y) || parent(root->right,x,y);
}
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        int level=0;
        int l1=-1;
        int l2=-1;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->val==x){
                    l1=level;
                }
                if(temp->val==y){
                    l2=level;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                 if(temp->right){
                    q.push(temp->right);
                }
            }
            
            if(l1!=l2){
                return false;
            }
            if(l1!=-1 && l2!=-1){
                break;
            }
            level++;
        }
        
        return !parent(root,x,y);
    }
};
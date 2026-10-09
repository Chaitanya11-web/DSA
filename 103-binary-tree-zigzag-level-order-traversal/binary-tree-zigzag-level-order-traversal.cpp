/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode* > L1;
        stack<TreeNode* > L2;
        vector<vector<int>> res;
if(root==NULL){
    return res;
}
        L1.push(root);
        while (!L1.empty() || !L2.empty()) {
            vector<int> ans;
            while (!L1.empty()) {
                TreeNode* temp = L1.top();
                ans.push_back(temp->val);
                L1.pop();
                if(temp->left){
             L2.push(temp->left);
                }
                if(temp->right){
                    L2.push(temp->right);

                }
            }
            if(!ans.empty()){
                res.push_back(ans);
                ans.clear();
            }
            while (!L2.empty()) {
                TreeNode* temp = L2.top();
                ans.push_back(temp->val);
                L2.pop();
                if(temp->right){
                    L1.push(temp->right);

                }
                if(temp->left){
             L1.push(temp->left);
                } 
            }
            if(!ans.empty()){
                res.push_back(ans);
                ans.clear();
            }

        }
        return res;
    }
};
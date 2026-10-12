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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        long long ans = INT_MIN;
         vector<long long> levelAns;
        while (!q.empty()) {
            int size = q.size();
            long long levelSum = 0;
           
            while (size--) {
                TreeNode* temp = q.front();
                q.pop();
                levelSum += temp->val;
               
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            level++;
             levelAns.push_back(levelSum);
        }
        sort(levelAns.begin(), levelAns.end());
        if(k>levelAns.size())return -1;
        return levelAns[levelAns.size() - k];
    }
};
class Solution {
public:
    void backtrack(int n, int k, int start, vector<int>& cur, vector<vector<int>>& res) {
        if ((int)cur.size() == k) {
            res.push_back(cur);
            return;
        }
        // prune: must leave enough numbers to fill the remaining spots
        for (int i = start; i <= n - (k - cur.size()) + 1; ++i) {
            cur.push_back(i);
            backtrack(n, k, i + 1, cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        if (k <= 0 || k > n) return res;
        backtrack(n, k, 1, cur, res);
        return res;
    }
};

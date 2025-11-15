class Solution {
public:
    vector<vector<int>> combination(vector<int>& candidates, int n, int i,
                                    int target, vector<int>& res,
                                    vector<vector<int>>& ans,
                                    set<vector<int>>& s) 
    {
        // If target reached
        if(target == 0) {
            // sort for dedup
            vector<int> temp = res;
            sort(temp.begin(), temp.end());

           // if(s.find(temp) == s.end()) {
                ans.push_back(temp);
                s.insert(temp);
           // }
            return ans;
        }

        if(target < 0 || i >= n) 
            return ans;

        for(int j = i; j < n; j++) {

            // ✔ Skip duplicates at same recursion level
            if(j > i && candidates[j] == candidates[j-1])
                continue;

            // ✔ If number is bigger than remaining target, break
            if(candidates[j] > target)
                break;

            // ✔ Choose this number
            res.push_back(candidates[j]);

            // ✔ Move to next index (never reuse same index)
            combination(candidates, n, j+1, target - candidates[j], res, ans, s);

            // ✔ Backtrack
            res.pop_back();
        }

        return ans;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());
        vector<int> res;
        set<vector<int>> s;

        return combination(candidates, candidates.size(), 0, target, res, ans, s);
    }
};

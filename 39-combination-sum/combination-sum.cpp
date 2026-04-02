class Solution {
public:

vector<vector<int>> combine(vector<int>& candidates, int n, int i, int target,
                           vector<int>& res, vector<vector<int>>& ans){

    // ✅ valid
    if(target == 0){
        ans.push_back(res);
        return ans;
    }

    // ❌ invalid
    if(i >= n || target < 0){
        return ans;
    }

    // ✅ INCLUDE (reuse allowed → stay at i)
    res.push_back(candidates[i]);
    combine(candidates, n, i, target - candidates[i], res, ans);
    res.pop_back();

    // ✅ EXCLUDE (move forward)
    combine(candidates, n, i+1, target, res, ans);

    return ans;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    int n = candidates.size();

    vector<vector<int>> ans;
    vector<int> res;

    return combine(candidates, n, 0, target, res, ans);
}
};
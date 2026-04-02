class Solution {
public:

vector<vector<int>> combine(vector<int>& candidates, int i, int n, int target,
                           vector<int>& res, vector<vector<int>>& ans){

    // ✅ valid
    if(target == 0){
        ans.push_back(res);
        return ans;
    }

    // ❌ invalid
    if(i == n || target < 0){
        return ans;
    }

    // ✅ INCLUDE
    res.push_back(candidates[i]);
    combine(candidates, i+1, n, target - candidates[i], res, ans);
    res.pop_back();

    // ✅ EXCLUDE (skip duplicates)
    int j = i+1;
    while(j < n && candidates[j] == candidates[j-1]){
        j++;
    }

    combine(candidates, j, n, target, res, ans);

    return ans;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> res;

    return combine(candidates, 0, candidates.size(), target, res, ans);
}
};
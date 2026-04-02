class Solution {
public:

vector<vector<int>> solve(int k, int n, int i, vector<int>& temp, vector<vector<int>>& ans){

    // ✅ valid case
    if(temp.size() == k && n == 0){
        ans.push_back(temp);
        return ans;
    }

    // ❌ invalid cases
    if(temp.size() > k || n < 0 || i > 9){
        return ans;
    }

    // ✅ INCLUDE
    temp.push_back(i);
    solve(k, n - i, i + 1, temp, ans);
    temp.pop_back();

    // ✅ EXCLUDE
    solve(k, n, i + 1, temp, ans);

    return ans;
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> temp;

    return solve(k, n, 1, temp, ans);
}
};
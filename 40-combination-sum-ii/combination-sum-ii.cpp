class Solution {
public:
vector<vector<int>>combine(vector<int>&candidates,int i,int n,int target,vector<int>&res,vector<vector<int>>&ans){
    if(target==0){
        sort(res.begin(),res.end());
        ans.push_back(res);
        return ans;
    }
    if(i==n || target<0){
        return ans;
    }
    for(int j=i;j<n;j++){
        if(j>i && candidates[j]==candidates[j-1]){
            continue;
        }
        if(candidates[j]>target){
            break;
        }
        res.push_back(candidates[j]);
        combine(candidates,j+1,n,target-candidates[j],res,ans);
        res.pop_back();
    }
    return ans;
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        vector<vector<int>>ans;
       return  combine(candidates,0,n,target,res,ans);
    }
};
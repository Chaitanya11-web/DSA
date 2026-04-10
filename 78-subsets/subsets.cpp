class Solution {
public:
void print(vector<int>&nums,int n,int i,vector<int>&res,vector<vector<int>>&ans){
if(i>=n){
    ans.push_back(res);
    //error
    return;
}
res.push_back(nums[i]);
print(nums,n,i+1,res,ans);
res.pop_back();
print(nums,n,i+1,res,ans);
}
    vector<vector<int>> subsets(vector<int>& nums) {
      int n=nums.size();
      vector<int>res;
        vector<vector<int>>ans;
        print(nums,n,0,res,ans);
        return ans;
    }
};
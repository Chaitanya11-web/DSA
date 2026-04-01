class Solution {
public:
vector<vector<int>>&permutation(vector<int>&nums,int n,int i,vector<int>&res,vector<vector<int>>&ans){
    if(i==n){
        ans.push_back(nums);
        return ans;
    }

for(int j=i;j<n;j++){
    swap(nums[i],nums[j]);
    permutation(nums,n,i+1,res,ans);
     swap(nums[i],nums[j]);
}
return ans;
}
    vector<vector<int>> permute(vector<int>& nums) {
      int  n=nums.size();
      vector<int>res;
      vector<vector<int>>ans;
      return permutation(nums,n,0,res,ans);  
    }
};
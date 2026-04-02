class Solution {
public:
 vector<vector<int>>subsets(vector<int>&nums,int n,int i,vector<int>&res,vector<vector<int>>&ans){
if(i>=n){
    ans.push_back(res);
    //sort(ans.begin(),ans.end());
    return ans;
}
res.push_back(nums[i]);
subsets(nums,n,i+1,res,ans);
res.pop_back();
int j=i+1;
while(j<n && nums[j]==nums[j-1]){//error
//yha continue work nhi krage kyuki vo skip karta h current iteration ko then move karta h next iteration par but yha koi inc nhi h na to vo bhar nikal ja rha h loop se
    j++;
}
//error jo index ab aaya h update hoke ussi se to continue karege na ki purna galat i se
subsets(nums,n,j,res,ans);
return ans;
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       int n=nums.size();
        vector<vector<int>>ans;
        vector<int>res;
        sort(nums.begin(),nums.end());
        return subsets(nums,n,0,res,ans);
    }
};
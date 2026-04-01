class Solution {
public:
//isme swapping 
vector<vector<int>>&permutation(vector<int>&nums,int n,int index,vector<vector<int>>&ans,set<vector<int>>&st){
if(index==n){
    if(st.find(nums)==st.end()){
        st.insert(nums);
        ans.push_back(nums);
    return ans;
    }
    
}
for(int j=index;j<n;j++){
    swap(nums[j],nums[index]);
    permutation(nums,n,index+1,ans,st);
     swap(nums[j],nums[index]);
    
}
return ans;
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     int n=nums.size();
     vector<vector<int>>ans;
     set<vector<int>>st;
     sort(nums.begin(),nums.end());
     return permutation(nums,n,0,ans,st);   
    }
};
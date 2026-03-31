class Solution {
public:
void permut(vector<int>&nums,int index,int n,set<vector<int>>&st,vector<vector<int>>&ans){
    if(index==n){
       if(st.find(nums)==st.end()){
ans.push_back(nums);
st.insert(nums);
       }
        
    }
    for(int i=index;i<n;i++){
       
         
        swap(nums[i],nums[index]);
        permut(nums,index+1,n,st,ans);
        swap(nums[i],nums[index]);
    }
 }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     int n=nums.size();
      vector<vector<int>>ans;
      set<vector<int>>st;
      //sort(nums.begin(),nums.end());
     permut(nums,0,n,st,ans); 
     return ans;  
    }
};
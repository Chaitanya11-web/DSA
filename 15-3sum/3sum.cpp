class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
       int k=0;
       int j=0;
        int sum=0;
         vector<vector<int>>ans;
         for(int i=0;i<n;i++){
            j=i+1;
            k=n-1;
            if(i>0 && nums[i]==nums[i-1])continue;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
if(sum<0){
  j++;  
}
else if(sum>0){
    k--;
}
else{
    vector<int>temp={nums[i],nums[j],nums[k]};
    ans.push_back(temp);
    j++;
    k--;
while(j<k && nums[j-1]==nums[j]){
    j++;
}
while(j<k && nums[k+1]==nums[k]){
    k--;
}
}
            }
         }
         return ans;
    }
};
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
      int j=0;
      for(int i=0;i<n;i++){
         j=(i+1)%n;
        while(j!=i){
            if(nums[j]>nums[i]){
ans[i]=nums[j];
break;
            }
            j=(j+1)%n;
        }
        
      }  
      return ans;
    }
};
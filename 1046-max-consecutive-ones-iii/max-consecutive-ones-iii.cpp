class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int n=nums.size();
      int i=0;
      int j=0;
      int maxLen=INT_MIN;
      while(j<n){
        if(nums[j]==0){
            k--;
           
            while(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
        }
         maxLen=max(j-i+1,maxLen);
        j++;
      }
      return maxLen;  
    }
};
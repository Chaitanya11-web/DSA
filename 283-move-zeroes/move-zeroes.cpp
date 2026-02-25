class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
      vector<int>temp(n,0);
      int j=0;
      for(int i=0;i<n;i++){
        if(nums[i]!=0){
            temp[j]=nums[i];
            j++;
        }
      } 
      for(int i=0;i<n;i++){
        nums[i]=temp[i];
      }
    }
};
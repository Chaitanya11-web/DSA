class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int ones=0;
       int twos=0;
       int threes=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        ones=(ones^nums[i])&(~twos);
        
        twos=(twos^nums[i])&(~ones);
       // threes=(threes^nums[i])&(~twos);
       } 
       return ones;
    }
};
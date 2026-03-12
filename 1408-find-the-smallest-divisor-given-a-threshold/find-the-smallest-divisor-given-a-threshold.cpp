class Solution {
public:
int calculate(int mid,vector<int>&nums){
int n=nums.size();
int sum=0;
int quot=0;
for(int i=0;i<n;i++){
    quot=(nums[i]+mid-1)/mid;
sum+=quot;
}
return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
      int n=nums.size();
      int sum=0;
      int res=0;
      int low=1;
      int maxi=INT_MIN;
      for(int i=0;i<n;i++){
maxi=max(maxi,nums[i]);
      } 
      int high=maxi;
      while(low<=high){
        int mid=low+(high-low)/2;
        int ans=calculate(mid,nums);
        if(ans>threshold){
            
            low=mid+1;
        }
        else{
            res=mid;
            high=mid-1;
        }
      }
      return res; 
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);
        int j=0;
        for(int i=0;i<n;i++){
if(nums[i]>0){
    temp[j]=nums[i];
    j=j+2;
}
        }
        j=1;
        for(int i=0;i<n;i++){
if(nums[i]<0){
    temp[j]=nums[i];
    j=j+2;
}
        }

  return temp;  }
};
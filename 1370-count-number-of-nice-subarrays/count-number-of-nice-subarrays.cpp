class Solution {
public:
int atMost(vector<int>&nums,int goal){
if(goal<0){
    return 0;
}
int i=0;
int j=0;
int n=nums.size();
int sum=0;
int cnt=0;
while(j<n){
sum+=nums[j]%2;
while(sum>goal){
if(nums[i]%2==1){
    sum-=nums[i]%2;
}
i++;
}
cnt+=j-i+1;
j++;
}
return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
       return atMost(nums,k)-atMost(nums,k-1); 
    }
};
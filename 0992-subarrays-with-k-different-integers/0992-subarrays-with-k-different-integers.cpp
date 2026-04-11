class Solution {
public:
int subarray(vector<int>&nums,int k){
int n=nums.size();
int cnt=0;
unordered_map<int,int>map1;
int i=0;
int j=0;
while(j<n){
map1[nums[j]]++;
if(map1.size()<=k){
cnt+=j-i+1;
}

while(map1.size()>k && i<n){
map1[nums[i]]--;
if(map1[nums[i]]==0){
    map1.erase(nums[i]);
}
i++;
if(map1.size()<=k){
    cnt+=j-i+1;
}

}

    j++;
}

return cnt;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
   int n=nums.size();
   return subarray(nums,k)-subarray(nums,k-1);  
    }
};
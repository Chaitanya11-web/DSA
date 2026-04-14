class Solution {
public:
int calc(vector<int>&nums,int k){
    if(k<0)return 0;
    int n=nums.size();
int cnt1=0;
unordered_map<int,int>map1;
int i=0;
int j=0;
while(j<n){
    map1[nums[j]]++;
// if(map1.size()<=k){
//     cnt1+=(j-i+1);

// }
while(map1.size()>k ){
    map1[nums[i]]--;
if(map1[nums[i]]==0){
    map1.erase(nums[i]);
}

i++;
}
//yaad rakhna jab map1.size()>k check kar liya to ek baar uske baad bhi check karo kyuki size map ka reduce ho gya hoga

    cnt1+=(j-i+1);


    j++;
}
return cnt1;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return calc(nums,k)-calc(nums,k-1);
    }
};
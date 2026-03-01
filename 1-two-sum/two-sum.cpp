class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map1;
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(map1.find(target-nums[i])==map1.end()){
                map1.insert({nums[i],i});
            }
            else{
return {i,map1[target-nums[i]]};
            }
        }
        return {0,0};
    }
};
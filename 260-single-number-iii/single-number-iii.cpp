class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>map1;
        for(int i=0;i<n;i++){
            if(map1.find(nums[i])==map1.end()){
                map1[nums[i]]++;
            }
            else{
                map1[nums[i]]++;
            }
        }
        for(auto it:map1){
            int u=it.first;
            int v=it.second;
            if(map1[u]==1){
               ans.push_back(u); 
            }
        }
        return ans;
    }
};
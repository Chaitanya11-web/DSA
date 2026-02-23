class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> t(n, INT_MAX);
        
        t[0] = 0;
        
        for(int i = 1; i < n; i++){
            for(int j = i-1; j >=0; j--){
                if(j + nums[j] >= i){
                    t[i] = min(t[i], t[j] + 1);
                }
            }
        }
        
        return t[n-1];
    }
};
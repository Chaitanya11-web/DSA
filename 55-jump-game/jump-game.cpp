class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n,0);
        t[0]=1;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(j+nums[j]>=i && t[j]==true){
                    t[i]=true;
                    break;
                }
            }
        }
        
        return t[n-1];
    }
};
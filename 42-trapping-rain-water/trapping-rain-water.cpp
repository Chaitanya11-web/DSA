class Solution {
public:
void getLeftMax(vector<int>&height,vector<int>&leftMax,int n){
for(int i=1;i<n;i++){
    leftMax[i]=max(leftMax[i-1],height[i]);
}
}
void  getRightMax(vector<int>&height,vector<int>&rightMax,int n){
for(int i=n-2;i>=0;i--){
    rightMax[i]=max(height[i],rightMax[i+1]);
}
}
    int trap(vector<int>& height) {
        int curr=0;
        int ans=0;
        int n=height.size();
        
        vector<int>leftMax(n,height[0]);
        vector<int>rightMax(n,height[n-1]);
        getLeftMax(height,leftMax,n);
        getRightMax(height,rightMax,n);
        for(int i=1;i<n-1;i++){
curr=min(leftMax[i],rightMax[i])-height[i];
ans+=curr;
        }
        return ans;
    }
};
class Solution {
public:
void findRightMax(vector<int>&rightMax,int n,vector<int>&height){
for(int i=n-2;i>=0;i--){
    rightMax[i]=max(height[i],rightMax[i+1]);
}
}
void findLeftMax(vector<int>&leftMax,int n,vector<int>&height){
for(int i=1;i<n;i++){
    leftMax[i]=max(height[i],leftMax[i-1]);
}
}
    int trap(vector<int>& height) {
       int n=height.size();
       int ans=0;
       vector<int>leftMax(n,height[0]) ;
      vector<int> rightMax(n,height[n-1]);
      findRightMax(rightMax,n,height);
      findLeftMax(leftMax,n,height);
       for(int  i=1;i<n-1;i++){
        ans+=min(leftMax[i],rightMax[i])-height[i];
       }
       return ans;
    }
};
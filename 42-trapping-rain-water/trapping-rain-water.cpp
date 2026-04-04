class Solution {
public:
void leftMax(vector<int>&height,int n,vector<int>& left){
for(int i=1;i<n;i++){
    // left[i-1] aayega jo val mil gyi usse compare karo
    left[i]=max(height[i],left[i-1]);
}

}
void rightMax(vector<int>&height,int n,vector<int>& right){
for(int i=n-2;i>=0;i--){
    // right[i+1] aayega jo val mil gyi usse compare karo
    right[i]=max(height[i], right[i+1]);
}
}
    int trap(vector<int>& height) {
        int sum=0;
      int n=height.size();
      vector<int>left(n,height[0]);
      vector<int>right(n,height[n-1]);
leftMax(height,n,left);
rightMax(height,n,right);
for(int i=0;i<n;i++){
    sum+=min(left[i],right[i])-height[i];
}
return sum;
    }
};
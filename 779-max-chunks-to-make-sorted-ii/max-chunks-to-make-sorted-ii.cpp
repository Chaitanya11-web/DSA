class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
     int n=arr.size();
     int cnt=0;
     vector<int>leftMax(n);
     vector<int>rightMin(n);
     rightMin[n-1]=arr[n-1];
     leftMax[0]=arr[0];
     for(int i=1;i<n;i++){
if(arr[i]>=leftMax[i-1]){
    leftMax[i]=arr[i];
}
else{
    leftMax[i]=leftMax[i-1];
}
     }   
     for(int i=n-2;i>=0;i--){
if(arr[i]<=rightMin[i+1]){
    rightMin[i]=arr[i];
}
else{
    rightMin[i]=rightMin[i+1];
}
     }
     int i=0;
     int j=1;
     while(i<n && j<n){
if(leftMax[i]<=rightMin[j]){
    cnt++;
    i++;
    j++;
}
else{
    i++;
    j++;
}
     }
return cnt+1;
    }
};
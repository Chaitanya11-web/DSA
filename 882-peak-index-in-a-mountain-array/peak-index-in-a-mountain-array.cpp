class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      int n=arr.size();
      //low=0 kabhi ans ho hi nhi sakta
      int low=1;
      //high kabhi ans nhi ho sakta
int high=n-2;
while(low<=high){
    int mid=low+(high-low)/2;
    if(arr[mid-1]<arr[mid]&& arr[mid]>arr[mid+1]){
        return mid;
    }
    else if(arr[mid]>arr[mid-1]){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
   return -1; }
};
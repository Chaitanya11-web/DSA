class Solution {
public:
    int mySqrt(int x) {
       int low=1;
       int high=x;
       long long val=-1;
       int ans=0;
       while(low<=high){
        long long mid=low+(high-low)/2;
val=mid*mid;
if(val<=x){
    ans=mid;
    low=mid+1;
}
else{
high=mid-1;
}
       } 
       return ans;
    }
};
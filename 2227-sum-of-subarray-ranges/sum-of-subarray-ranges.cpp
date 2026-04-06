class Solution {
public:
long long sumSubarrayMin(vector<int>&nums){
 int mod=1000000007;
       int n=nums.size();
       vector<int>nsl(n,-1);
       vector<int>nsr(n,n);
       stack<pair<int,int>>st1;
       stack<pair<int,int>>st2;
       long long ans=0;
       for(int i=n-1;i>=0;i--){
        while(!st1.empty() && st1.top().first>=nums[i]){
            st1.pop();
        }
        if(!st1.empty()){
            nsr[i]=st1.top().second;
        }
        st1.push({nums[i],i});
       } 
       for(int i=0;i<n;i++){
        //remember dono jagah include nhi karna = equal value ko
        while(!st2.empty() && st2.top().first>nums[i]){
            st2.pop();
        }
        if(!st2.empty()){
            nsl[i]=st2.top().second;
        }
        st2.push({nums[i],i});
       } 
       for(int i=0;i<n;i++){
        long long left=(i-nsl[i]);
        long long right=(nsr[i]-i);
ans+=left*right*nums[i];
       }
       return ans;
}


long long sumSubarrayMax(vector<int>&nums){
 int mod=1000000007;
       int n=nums.size();
       vector<int>ngl(n,-1);
       vector<int>ngr(n,n);
       stack<pair<int,int>>st1;
       stack<pair<int,int>>st2;
       long long ans=0;
       for(int i=n-1;i>=0;i--){
        while(!st1.empty() && st1.top().first<=nums[i]){
            st1.pop();
        }
        if(!st1.empty()){
            ngr[i]=st1.top().second;
        }
        st1.push({nums[i],i});
       } 
       for(int i=0;i<n;i++){
        //remember dono jagah include nhi karna = equal value ko
        while(!st2.empty() && st2.top().first<nums[i]){
            st2.pop();
        }
        if(!st2.empty()){
            ngl[i]=st2.top().second;
        }
        st2.push({nums[i],i});
       } 
       for(int i=0;i<n;i++){
        long long left=(i-ngl[i]);
        long long right=(ngr[i]-i);
ans+=left*right*nums[i];
       }
       return ans;
}

    long long subArrayRanges(vector<int>& nums) {
      int n1=nums.size();
      int mod=1000000007;
      return (sumSubarrayMax(nums)-sumSubarrayMin(nums));  
    }
};
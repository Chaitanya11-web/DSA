class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
    // long long mod = 1000000007;
     stack<pair<int,int>>st1;
     stack<pair<int,int>>st2;
      stack<pair<int,int>>st3;
       stack<pair<int,int>>st4;
     vector<int>nsr(n,n);
     vector<int>nsl(n,-1);
    vector<int>ngr(n,n);
    vector<int>ngl(n,-1);
     long long ans1=0;
     long long ans2=0;
       for(int i=0;i<n;i++){
while(!st1.empty()&& nums[i]<st1.top().first ){
    st1.pop();
}
if(!st1.empty()){
    nsl[i]=st1.top().second;
}
st1.push({nums[i],i});
     } 
    for(int i=n-1;i>=0;i--){
while(!st2.empty()&& nums[i]<=st2.top().first ){
    st2.pop();
}
if(!st2.empty()){
    nsr[i]=st2.top().second;
}
st2.push({nums[i],i});
     }  
for(int i=0;i<n;i++){
    long long left=i-nsl[i];
    long long right=nsr[i]-i;
    ans1+=(left*right)*nums[i];
}
for(int i=0;i<n;i++){
while(!st3.empty()&& nums[i]>st3.top().first ){
    st3.pop();
}
if(!st3.empty()){
    ngl[i]=st3.top().second;
}
st3.push({nums[i],i});
     } 
     for(int i=n-1;i>=0;i--){
while(!st4.empty()&& nums[i]>=st4.top().first ){
    st4.pop();
}
if(!st4.empty()){
    ngr[i]=st4.top().second;
}
st4.push({nums[i],i});
     } 
     for(int i=0;i<n;i++){
    long long left=i-ngl[i];
    long long right=ngr[i]-i;
    ans2+=(left*right)*nums[i];
}
 return ans2-ans1;
    }
};
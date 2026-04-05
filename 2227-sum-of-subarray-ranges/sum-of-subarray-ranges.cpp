class Solution {
public:
long long subarrayMax(vector<int>& nums){
int n=nums.size();
long long left=0;
long long right=0;
long long ans=0;
stack<pair<int,int>>st1;
stack<pair<int,int>>st2;
vector<int>ngl(n,-1);
vector<int>ngr(n,n);
for(int i=0;i<n;i++){
    while(!st1.empty() && st1.top().first<=nums[i]){
        st1.pop();
    }
    if(!st1.empty()){
        ngl[i]=st1.top().second;
    }
st1.push({nums[i],i});
}
for(int i=n-1;i>=0;i--){
    while(!st2.empty() && st2.top().first<nums[i]){
        st2.pop();
    }
    if(!st2.empty()){
        ngr[i]=st2.top().second;
    }
st2.push({nums[i],i});
}
for(int i=0;i<n;i++){
    left=i-ngl[i];
    right=ngr[i]-i;
ans+=left*right*nums[i];
}
return ans;
}
long long subarrayMin(vector<int>& nums){
int n=nums.size();
long long left=0;
long long right=0;
long long ans=0;
stack<pair<int,int>>st1;
stack<pair<int,int>>st2;
vector<int>nsl(n,-1);
vector<int>nsr(n,n);
for(int i=0;i<n;i++){
    while(!st1.empty() && st1.top().first>=nums[i]){
        st1.pop();
    }
    if(!st1.empty()){
        nsl[i]=st1.top().second;
    }
st1.push({nums[i],i});
}
for(int i=n-1;i>=0;i--){
    while(!st2.empty() && st2.top().first>nums[i]){
        st2.pop();
    }
    if(!st2.empty()){
        nsr[i]=st2.top().second;
    }
st2.push({nums[i],i});
}
for(int i=0;i<n;i++){
    left=i-nsl[i];
    right=nsr[i]-i;
ans+=left*right*nums[i];
}
return ans;
}


    long long subArrayRanges(vector<int>& nums) {
        
        return subarrayMax(nums)-subarrayMin(nums);
    }
};
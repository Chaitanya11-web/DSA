class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
     int n=arr.size();
     long long mod = 1000000007;
     stack<pair<int,int>>st1;
     stack<pair<int,int>>st2;
     vector<int>nsr(n,n);
     vector<int>nsl(n,-1);
    
     long long ans=0;
       for(int i=0;i<n;i++){
while(!st1.empty()&& arr[i]<st1.top().first ){
    st1.pop();
}
if(!st1.empty()){
    nsl[i]=st1.top().second;
}
st1.push({arr[i],i});
     } 
    for(int i=n-1;i>=0;i--){
while(!st2.empty()&& arr[i]<=st2.top().first ){
    st2.pop();
}
if(!st2.empty()){
    nsr[i]=st2.top().second;
}
st2.push({arr[i],i});
     }  
for(int i=0;i<n;i++){
    long long left=i-nsl[i];
    long long right=nsr[i]-i;
    ans+=(left*right)*arr[i];
}
 return ans%mod;
   }
};
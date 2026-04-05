class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      int n=arr.size();
      int mod=1000000007;
      stack<pair<int,int>>st1;
      stack<pair<int,int>>st2;  
      vector<int>nsl(n,-1);
      vector<int>nsr(n,n);
      long long left=0;
      long long right=0;
      long long ans=0;
      for(int i=0;i<n;i++){
        while(!st1.empty() && st1.top().first>=arr[i]){
  st1.pop();
        }
      
      
      if(!st1.empty()){
        nsl[i]=st1.top().second;
      }
st1.push({arr[i],i});
    }
     for(int i=n-1;i>=0;i--){
        while(!st2.empty() && st2.top().first>arr[i]){
  st2.pop();
        }
      
      
      if(!st2.empty()){
        nsr[i]=st2.top().second;
      }
st2.push({arr[i],i});
    }
    for(int i=0;i<n;i++){
left=i-nsl[i];
right=nsr[i]-i;
ans+=arr[i]*left*right;
    }
    //remeber ans can be very long
    return ans%mod;
    }  
};
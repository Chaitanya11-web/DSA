class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=INT_MIN;
      
        stack<pair<int,int>>st1;
        stack<pair<int,int>>st2;
        vector<int>nsr(n,n);
        vector<int>nsl(n,-1);
        int curr=0;
        for(int i=n-1;i>=0;i--){
while(!st1.empty() && heights[i]<=st1.top().first){
    
    st1.pop();
}
if(!st1.empty()){
    nsr[i]=st1.top().second;
}
st1.push({heights[i],i});
        }
        for(int i=0;i<n;i++){
while(!st2.empty() && heights[i]<=st2.top().first){
  
    st2.pop();
}
if(!st2.empty()){
    nsl[i]=st2.top().second;
}
st2.push({heights[i],i});
        }

        for(int i=0;i<n;i++){
curr=(nsr[i]-nsl[i]-1)*heights[i];
if(curr>maxi){
    maxi=curr;
}
        }
        return maxi;
    }
};
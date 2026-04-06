class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int sum=0;
        stack<int>st;
       
        for(auto a:asteroids){
while(!st.empty() && a<0 && st.top()>0){
    sum=a+st.top();
    if(sum<0){
        st.pop();
    }
    else if(sum>0){
        a=0;
    }
    else{
        a=0;
        st.pop();
    }
}
if(a!=0){
st.push(a);
}

        }
       int n=st.size();
        vector<int>ans(n);
       for(int i=n-1;i>=0;i--){
        ans[i]=st.top();
        st.pop();
       }
    return ans;
    }
    
};
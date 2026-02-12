class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
       
        int n=asteroids.size();
        int sum=0;
        for(auto a:asteroids){
            while(!st.empty() && a<0 && st.top()>0 ){
                sum=a+st.top();
                if(sum>0){
                    a=0;
                }
                else if(sum<0){
                    st.pop();
                }
                else{
                    //sum==0
                    a=0;
                    st.pop();
                }
            }
            if(a!=0){
                st.push(a);
            }
        }
        int n1=st.size();
        vector<int>ans(n1,0);
while(!st.empty()){
ans[n1-1]=st.top();
st.pop();
n1--;
}

  return ans;  }
};
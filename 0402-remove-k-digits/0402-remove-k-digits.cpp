class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.length();
       
        for(int i=0;i<n;i++){
while(!st.empty() && st.top()>num[i] && k!=0)
            {
                st.pop();
                    k--;
            }
           
            st.push(num[i]);
        }
        while(k!=0){
st.pop();
k--;
        }
        int n1=st.size();
         string ans(n1,' ');
for(int i=n1-1;i>=0;i--){
    ans[i]=st.top();
    st.pop();
}
int j=0;
while(ans[j]=='0'){
    j++;
}
if(ans.substr(j)==""){
    return "0";
}
  return ans.substr(j);  }
};
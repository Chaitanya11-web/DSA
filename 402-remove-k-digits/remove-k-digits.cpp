class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        if(k==num.size())return "0";
        for(int i=0;i<n;i++){
        while(!st.empty() && num[i]<st.top() && k!=0){
            st.pop();
           k--;
        }
         st.push(num[i]);
        }
        while(!st.empty() && k>0 ){
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
        while(j<n1 && ans[j]=='0'){
            j++;
           
        }
       // ans=ans.substr(j);
        if(ans.substr(j)==""){
            return "0";
         }
         
         
         
        return ans.substr(j);
    }
};
class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n=nums.size();
        //imp
        stack<char>st;
        for(int i=0;i<n;i++){
            //K>0 with applied condition of monotonic stack
            while(!st.empty() && st.top()>nums[i] && k>0){
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        while(!st.empty() && k>0){
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
if(ans.substr(j)==""){
    return "0";
}
return ans.substr(j);
    }
};
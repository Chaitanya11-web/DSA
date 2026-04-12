class Solution {
public:
    string removeOuterParentheses(string s) {
       int n=s.length();
       string res;
       int count=0;
       for(int i=0;i<n;i++){
if(s[i]==')')count--;
if(count!=0)res.push_back(s[i]);
if(s[i]=='(')count++;
       } 
       return res;
    }
};
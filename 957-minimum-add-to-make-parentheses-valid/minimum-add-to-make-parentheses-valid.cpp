class Solution {
public:
    int minAddToMakeValid(string s) {
      stack<int>stack1;
      int n=s.length();
      int count=0;
      for(int i=0;i<n;i++){
        if(s[i]=='('){
            stack1.push('(');
        }
        else{
if(stack1.size()==0){
    count++;
}
else{
    stack1.pop();
}
        }
      } 
  return stack1.size()+count;  }
};
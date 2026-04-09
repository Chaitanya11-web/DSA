class Solution {
public:
    bool rotateString(string s, string goal) {
      int m=s.length()+s.length();
      int n=goal.length();
      string str=s+s;
      bool ans=false;
      if(s.length()!=goal.length())return false;
for(int i=0;i<=n;i++){
    //remember
    if(str.substr(i,n)==goal){
return true;
    }
}
return false;
    }
};
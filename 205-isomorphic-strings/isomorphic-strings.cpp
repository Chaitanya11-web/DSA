class Solution {
public:
    bool isIsomorphic(string s, string t) {
      int m=s.length();
      int n=t.length();
      bool ans=true;
      if(m!=n){
        return false;
      }  
      unordered_map<char,int>map1;
      unordered_map<char,int>map2; 
      map1[s[0]]=1;
      map2[t[0]]=1;
      for(int i=1;i<m;i++){
if(map1.find(s[i])==map1.end()){
    map1[s[i]]=i+1;
}
if(map2.find(t[i])==map2.end()){
    map2[t[i]]=i+1;
}
if(map1[s[i]]==map2[t[i]]){
    ans=true;
}
else{
    ans=false;
    return false;
}
      }
      return ans;
    }
};
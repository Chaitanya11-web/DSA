class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        int n=s.length();
      unordered_map<char,int>map1{
{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
      } ; 
      for(int i=0;i<n;i++){
        if(i<n-1 && map1[s[i]]<map1[s[i+1]]){
            ans+=map1[s[i+1]]-map1[s[i]];
            i++;
        }
        else{
            ans+=map1[s[i]]; 
        }
//         if(i>0 && map1[s[i]]>map1[s[i+1]]){
// ans=map1[s[i]]-map1[s[i+1]];
//         }
      }
      return ans;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
      int n=s.length();
      int m=t.length();
      int start_idx=0;
      int i=0;
      int j=0;
      int requiredCount=m;
      int minWindowSize=INT_MAX;
      if(m>n){
        return "";
      }
      unordered_map<char,int>map1;
for(int i=0;i<m;i++){
    map1[t[i]]++;
}
while(j<n){
char ch=s[j];
if(map1[ch]>0){
  requiredCount--;  
}
map1[ch]--;
while(requiredCount==0){
    int currWindowSize=j-i+1;
    if(minWindowSize>currWindowSize){
        minWindowSize=currWindowSize;
        start_idx=i;
    }
    map1[s[i]]++;
    if(map1[s[i]]>0){
        requiredCount++;
    }
    i++;
}
j++;
}
 return minWindowSize==INT_MAX? "":s.substr(start_idx,minWindowSize);   }
};
class Solution {
public:
bool allZero(unordered_map<int,int>&map1){

for(auto it:map1){
if(it.second!=0){
    return false;
}
}
return true;
}
    vector<int> findAnagrams(string s, string p) {
      int m=s.size();
      int n=p.size();
      int i=0;
      int j=0;
      int cnt=0;
      vector<int>ans;
      unordered_map<int,int>map1;
      for(int i=0;i<n;i++){
        map1[p[i]]++;
      }
      while(j<m){
        if(map1.find(s[j])!=map1.end()){
            map1[s[j]]--;
        }
if(j-i+1==n){
    if(allZero(map1)){
        cnt++;
ans.push_back(i);
}

if(map1.find(s[i])!=map1.end()){
map1[s[i]]++;
}
i++;
    
   
   
}

j++;
      }
      return ans;
    }
};
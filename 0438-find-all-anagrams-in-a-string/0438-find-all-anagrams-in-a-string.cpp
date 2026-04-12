class Solution {
public:
bool allCount(unordered_map<char,int>&map1){
for(auto it:map1){
    if(it.second!=0){
        return false;
    }
}
return true;
}
    vector<int> findAnagrams(string s, string p) {
       int n=s.length();
       int m=p.length();
       int cnt=0;
       vector<int>ans;
       int i=0;
       int  j=0;
       unordered_map<char,int>map1;
       for(int i=0;i<m;i++){
        map1[p[i]]++;
       }
       while(j<n){
if(map1.find(s[j])!=map1.end()){
    map1[s[j]]--;
}
if(j-i+1==m){
    if(allCount(map1)){
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
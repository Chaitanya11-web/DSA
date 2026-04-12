class Solution {
public:
int atMost(string s,int goal){
int n=s.length();
        int i=0;
        int j=0;
        int cnt=0;
        int k=goal;
        unordered_map<int,int>map1;
        while(j<n){
map1[s[j]]++;
while(map1.size()>k){
map1[s[i]]--;
if(map1[s[i]]==0){
    map1.erase(s[i]);
}
i++;
}
cnt+=j-i+1;
            j++;
        }
        return cnt;
}
    int numberOfSubstrings(string s) {
      return atMost(s,3)-atMost(s,2);  
    }
};
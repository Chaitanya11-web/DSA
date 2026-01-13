class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
       unordered_map<char,int>map1;
       for(char c:s){
        map1[c]++;
       }
       for(int i=0;i<n;i++){
        if(map1[s[i]]==1){
            return i;
        }
       }
       return -1;
    }
};
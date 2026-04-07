class Solution {
public:
    int characterReplacement(string s, int k) {
       int n=s.length();
       unordered_map<int,int>map1;
       int maxFreq=0;
       int cntStr=0;
       int i=0;
       int j=0;
       while(j<n){
map1[s[j]]++;
if(maxFreq<map1[s[j]]){
    maxFreq=map1[s[j]];
}
if((j-i+1)-maxFreq<=k){
    if(cntStr<(j-i+1)){
        cntStr=j-i+1;
    }
}
else{
    if((j-i+1)-maxFreq>k){
        map1[s[i]]--;
        i++;
    }
}

        j++;
       } 
       return cntStr;
    }
};
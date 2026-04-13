class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxFreq=0;
        unordered_map<char,int>map1;
        int maxLen=INT_MIN;
        int i=0;
        int j=0;
        while(j<n){
            map1[s[j]]++;
            if(maxFreq<map1[s[j]]){
                maxFreq=map1[s[j]];
                
            }
            if((j-i+1)-maxFreq<=k){
                maxLen=max(maxLen,j-i+1);
            }
              if ((j-i+1)-maxFreq>k){
                map1[s[i]]--;
                if(map1[s[i]]==0){
                    map1.erase(s[i]);
                }
i++;
            }
            j++;
        }
       return maxLen;
    }
};
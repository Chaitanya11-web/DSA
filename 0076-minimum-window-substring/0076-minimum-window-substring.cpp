class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        if(n>m)return "";
        int i=0;
        int start=-1;
        int minLen=INT_MAX;
        int j=0;
        unordered_map<char,int>map1;
        for(int i=0;i<n;i++){
            map1[t[i]]++;
        }
        int reqCnt=n;
        while(j<m){
            if(map1.find(s[j])!=map1.end()){
        if(map1[s[j]]>0){
              reqCnt--;
                }
            }
            map1[s[j]]--;

while(reqCnt==0){

if(minLen>(j-i+1)){
    minLen=j-i+1;
    start=i;
}

   map1[s[i]]++;
   if(map1[s[i]]>0){
    reqCnt++;
   }
   i++;
}
j++;
        }
        return start==-1?"":s.substr(start,minLen);
    }
};
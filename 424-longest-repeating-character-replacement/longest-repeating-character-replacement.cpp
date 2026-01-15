class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int k1=1;
        bool ans=false;
//         while(k1<n){
// if(s[k1]==s[k1-1]){
//     ans=true;
// }
// else{
//     ans=false;
//     break;
// }
//     k1++;    }
//         if(ans==true){
//             return n;
//         }
       vector<int>map1(256,0);
       int i=0;
       int j=0;
       int maxFreq=0;
       int cntStr=0;
       
       while(j<n){
        map1[s[j]]++;
        if(maxFreq<map1[s[j]]){
maxFreq=map1[s[j]];
        }

if((j-i+1)-maxFreq<=k){
    if((j-i+1)>cntStr){
        cntStr=j-i+1;
    }
}

else{
  if((j-i+1)-maxFreq>k){
    map1[s[i]]--;
    i++; 
}
}
    j++;   } 
 return cntStr;  
  }
};
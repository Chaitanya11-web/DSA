class Solution {
public:
bool isAllZero(unordered_map<char,int>&map){
           for(auto it:map){
               int cnt=it.second;
               if(cnt!=0){
                   return false;
               }
           }
           return true;
       }
    vector<int> findAnagrams(string s, string p) {
         vector<int>ans;
                unordered_map<char,int>map1;
        int sum=0;
        int cntStr=0;
        int n=s.length();
        int m=p.length();
        for(int i=0;i<m;i++){
            map1[p[i]]++;
        }
        
        int i=0;
        int j=0;
      
        while(j<n){
            if(map1.find(s[j])!=map1.end()  ){
               
                map1[s[j]]--;
                
            }
           if(j-i+1==m){
               if(isAllZero(map1)){
                ans.push_back(i);
                cntStr+=1;   
               }
               if(map1.find(s[i])!=map1.end()){
                   map1[s[i]]+=1;
                   
               }
              i++; 
           } 
            
            
            j++;
        }
        return ans;
    }
};
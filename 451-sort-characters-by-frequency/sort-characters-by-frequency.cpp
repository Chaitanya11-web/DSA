class Solution {
public:
    string frequencySort(string s) {
      string res;
      vector<int>freq;
      unordered_map<char,int>map1;
      int n=s.length();
      for(int i=0;i<n;i++){
        map1[s[i]]++;
      }  
      for(auto it:map1){
        int cnt=it.second;
        freq.push_back(cnt);
      }
      sort(freq.begin(),freq.end());
      
      for(int j=freq.size()-1;j>=0;j--){
      for(auto it:map1){
       if( map1[it.first] ==freq[j] ){
        res+= string(freq[j], it.first);
       map1[it.first]=-1;
       break;
        
       }
      }
      }
      return res;
    }
};
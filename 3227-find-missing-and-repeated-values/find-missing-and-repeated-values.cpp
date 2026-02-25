class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      vector<int>ans;
      map<int,int>map1;
       int sn=0;
      int repeat=0;
      int sum=0;
      int actual=0;
      int m=grid.size();
      int n=grid[0].size();
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
map1[grid[i][j]]++;
        }
      }
        int size=map1.size();
        for(auto it:map1){
            int u=it.first;
            int v=it.second;
            sum+=u;
            if(v>1){
                repeat=u;
            }
        }
        
       
      
      actual=m*n;
        sn=(actual*(actual+1) )/2;
      return {repeat,sn-sum}; 
    }
};
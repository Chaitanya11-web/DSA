class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
      int m=grid.size();
      int n=grid[0].size();
      int newCost=0;
      vector<vector<int>>distance(m,vector<int>(n,INT_MAX));
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
      distance[0][0]=grid[0][0];
      pq.push({distance[0][0],{0,0}});
      while(!pq.empty()){
        pair<int,pair<int,int>>p=pq.top();
        int cost=p.first;
        int i=p.second.first;
        int j=p.second.second;
        pq.pop();
        if(i==m-1 && j==n-1)return distance[i][j];
       //if (cost > distance[i][j]) continue;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int d=0;d<4;d++){
            int ni=i+dx[d];
            int nj=j+dy[d];
            if(ni>=0 && nj>=0 && ni<m && nj<n){
 newCost=max(cost,grid[ni][nj]);
if(newCost<distance[ni][nj]){
    distance[ni][nj]=newCost;
    pq.push({newCost,{ni,nj}});
}
            }

        }
        
              }  
 return -1;   }
};
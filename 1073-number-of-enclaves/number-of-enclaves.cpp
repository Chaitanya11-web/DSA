class Solution {
public:
void  dfs( vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<int>>&visited){
if(i<0 || j<0 || i>=m || j>=n || visited[i][j]==1 || grid[i][j]==0){
    return;
}
visited[i][j]=1;
 dfs( grid,i+1,j,m,n,visited);
  dfs( grid,i-1,j,m,n,visited);
   dfs( grid,i,j+1,m,n,visited);
    dfs( grid,i,j-1,m,n,visited);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dfs( grid,i,0,m,n,visited);
             dfs( grid,i,n-1,m,n,visited);
        }
        for(int j=0;j<n;j++){
        dfs( grid,0,j,m,n,visited);
        dfs( grid,m-1,j,m,n,visited);  
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
if(visited[i][j]==0 && grid[i][j]==1){
cnt++;
}
            }
        }
        return cnt;
    }
};
class Solution {
public:
bool  dfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int i,int j,int m,int n){
    
    if(i<0 || j<0 || i>=m || j>=n   ){
        return false;
    }
    if(grid[i][j]==1){
        return true;
    }
    if (visited[i][j]) return true;
    visited[i][j]=1;
  
    bool left=   dfs(grid,visited,i-1,j,m,n);
    bool  right=   dfs(grid,visited,i,j+1,m,n);
    bool  top=   dfs(grid,visited,i+1,j,m,n);
    bool bottom=   dfs(grid,visited,i,j-1,m,n);
    
    return left && right && top && bottom;
}
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if(visited[i][j]==0 && grid[i][j]==0){
                   if( dfs(grid,visited,i,j,m,n)){
                    count++;}
                }
            }
        }
return count;
    }
};
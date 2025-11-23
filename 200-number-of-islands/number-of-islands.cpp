class Solution {
public:
 void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&visited,int m,int n){
if(i<0 || j<0 ||i>=m || j>=n || grid[i][j]=='0' || visited[i][j]==1){
    return;
}
visited[i][j]=1;
dfs(i-1,j,grid,visited,m,n);//top
dfs(i,j+1,grid,visited,m,n);//right
dfs(i+1,j,grid,visited,m,n);//bottom
dfs(i,j-1,grid,visited,m,n);//left
 }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    dfs(i,j,grid,visited,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};
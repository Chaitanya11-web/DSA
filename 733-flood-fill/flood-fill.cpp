class Solution {
public:
void dfs(vector<vector<int>>&image,int i,int j,int color,vector<vector<int>>&visited,int m,int n,int original){
if(i<0 || j<0 || i>=m || j>=n || visited[i][j]==1 || image[i][j]==color){
    return;
}
else if(image[i][j]==original){
   image[i][j]=color;
   visited[i][j]=1;
  dfs(image,i-1,j,color,visited,m,n,original); 
   dfs(image,i,j+1,color,visited,m,n,original);
    dfs(image,i+1,j,color,visited,m,n,original);
     dfs(image,i,j-1,color,visited,m,n,original);
}
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int original=image[sr][sc];
        if(original!=color){
            dfs(image,sr,sc,color,visited,m,n,original);
        }
        return image;
    }
};
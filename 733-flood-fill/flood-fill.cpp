class Solution {
public:
 void dfs(vector<vector<int>>&image,int i,int j,int m,int n,int color,vector<vector<int>>& visited,int original){
if( i<0 || j<0 || i>=m || j>=n ||visited[i][j]==1 || image[i][j]==color || image[i][j]!=original){
    return;
}
else if(image[i][j]==original){
    image[i][j]=color;
    visited[i][j]=1;
}


     dfs(image,i-1,j,m,n,color,visited,original);
      dfs(image,i+1,j,m,n,color,visited,original);
    dfs(image,i,j-1,m,n,color,visited,original);
    dfs(image,i,j+1,m,n,color,visited,original);

 }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      int original=image[sr][sc];
      int m=image.size();
      int n=image[0].size();
      vector<vector<int>>visited(m,vector<int>(n,0));
      if(original!=color){
      dfs(image,sr,sc,m,n,color,visited,original);}
return image;
    }
};
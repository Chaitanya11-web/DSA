class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>distance(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int>p=q.front();
            int i=p.first;
            int j=p.second;
            q.pop();

            if(mat[i][j]==0 && distance[i][j]==-1)distance[i][j]=0; 
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1}; 
            for(int d=0;d<4;d++){
                int ni=i+dx[d];
                int nj=j+dy[d];
                if(ni>=0 && nj>=0 && ni<m && nj<n && distance[ni][nj]==-1){
                    
                    if(mat[ni][nj]==0){
                       
                        distance[ni][nj]=0;
                    }
                    else if(mat[ni][nj]==1){
                         q.push({ni,nj});
                      distance[ni][nj]=1+distance[i][j];
                    }
                }
            }

        }
        return distance;

    }
};
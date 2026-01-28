class Solution {
public:
void  dfs(vector<vector<int>>&stones,int node,vector<int>&visited,int n){
int row=stones[node][0];
int col=stones[node][1];

for(int i=0;i<n;i++){
    int r=stones[i][0];
    int c=stones[i][1];
    if(visited[i]==0 && (r==row || c==col)){
        visited[i]=1;
dfs(stones,i,visited,n);
    }
}

}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>visited(n,0);
        int grp=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(stones,i,visited,n);
                grp++;
            }
        }
        return n-grp;
    }
};
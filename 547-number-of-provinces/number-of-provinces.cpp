class Solution {
public:
void  dfs(vector<vector<int>>& list,int i,vector<int>& visited){
int node=i;
visited[node]=1;
for(int i=0;i<list[node].size();i++){
    if(visited[list[node][i]]!=1){
    dfs(list,list[node][i],visited);
    }
}
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<vector<int>>list(V);
        int count=0;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i==j){
                    continue;
                }
                if(isConnected[i][j]==1){
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
       for(int i=0;i<V;i++){
        if(visited[i]!=1){
            dfs(list,i,visited);
            count++;
        }
       }
       return count;
    }
};
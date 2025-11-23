class Solution {
public:
bool  dfs(vector<vector<int>>&list, vector<int>&visited,int i,int destination){
    int node=i;
    visited[node]=1;
    for(int i=0;i<list[node].size();i++){
        int curr=list[node][i];
        if(curr==destination){
            return true;
        }
        else if(visited[curr]==0){
           if( dfs(list,visited,curr,destination)){
            return true;
           }
        }
    }
return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination){
            return true;
        }
       vector<vector<int>>list(n);
       for(auto it:edges){
        int u=it[0];
        int v=it[1];
        list[u].push_back(v);
        list[v].push_back(u);
       }
       vector<int>visited(n,0);
      // for(int i=source;i<n;i++){
        //if(visited[i]==0){
           if( dfs(list,visited,source,destination)){
            return true;
           //}
        }
      // } 
       return false;
    }
};
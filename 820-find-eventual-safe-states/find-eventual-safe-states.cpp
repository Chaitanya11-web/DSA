class Solution {
public:
bool dfs(vector<int>&visited,vector<int>&pathVisited,int i,vector<vector<int>>&graph){
      int node=i;
      pathVisited[node]=1;
      visited[node]=1;
      for(int i=0;i<graph[node].size();i++){
          int curr=graph[node][i];
          if(visited[curr]==0){
              if(dfs(visited,pathVisited,curr,graph)){
                  return true;
              }
          }
          else if(pathVisited[curr]==1){
              return true;
          }
      }
      pathVisited[node]=0;
    return false;  
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          bool ans=false;
        vector<int>ans1;
        int V=graph.size();
        vector<int>pathVisited(V,0);
         vector<int>visited(V,0);
        // for(auto it:graph){
        //     int u=it[0];
        //     int v=it[1];
        //     list[u].push_back(v);
        // }
        for(int i=0;i<V;i++){
            if(visited[i]==0){
               if( dfs(visited,pathVisited,i,graph)){
                   ans=true;
                   
               }
            }
        }
        
        for(int i=0;i<V;i++){
            if(pathVisited[i]==false){
                ans1.push_back(i);
            }
        }
        
     return ans1;   
    }
};
class Solution {
public:
void dfs(vector<vector<int>>&graph,int i,int dest,vector<int>&res, vector<vector<int>>&ans,vector<int>&visited){
int node=i;
visited[node]=1;
res.push_back(node);
for(int i=0;i<graph[node].size();i++){
    int curr=graph[node][i];
    if(curr==dest){
        res.push_back(curr);
        ans.push_back(res);
        
    }
    else if(visited[curr]==0){
        
        dfs(graph,curr,dest,res,ans,visited);
       
    }
     visited[curr]=0;
res.pop_back();
}

}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>ans;
        vector<vector<int>>list(V);
        vector<int>visited(V,0);

if(visited[0]==0){
    vector<int>res;
 dfs(graph,0,V-1,res,ans,visited);
}
return ans;    }
};
class Solution {
public:
 void dfs(int node,int parent,vector<vector<int>>&list,  vector<int>&disc,  vector<int>&low,  vector<bool>&visited,int n,int& cnt,vector<vector<int>>&bridges){
disc[node]=cnt;
low[node]=cnt;
visited[node]=1;
for(int i=0;i<list[node].size();i++){
    int curr=list[node][i];
    if(curr==parent)continue;

    else if(visited[curr]==1){
        low[node]=min(low[node],low[curr]);
    }
    else{
        cnt++;
        dfs(curr,node,list,disc,low,visited,n,cnt,bridges);
       low[node]=min(low[node],low[curr]);
        if(disc[node]<low[curr]){
            vector<int>temp;
temp.push_back(curr);
temp.push_back(node);
bridges.push_back(temp);
        }
        
    }
}



 }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       vector<vector<int>>list(n);
       for(auto it:connections){
        int u=it[0];
        int v=it[1];
        list[u].push_back(v);
        list[v].push_back(u);
       } 
        vector<vector<int>>bridges;
        vector<int>disc(n);
        vector<int>low(n);
        vector<bool>visited(n,0);
        int cnt=0;
        dfs(0,-1,list,disc,low,visited,n,cnt,bridges);
        return bridges;
    }
};
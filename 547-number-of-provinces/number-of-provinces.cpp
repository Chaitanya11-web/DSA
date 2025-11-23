class Solution {
public:
 void dfs(vector<vector<int>>&list,int i,vector<int>&visited){
    int node=i;
    visited[node]=1;
    for(int i=0;i<list[node].size();i++){
        int curr=list[node][i];
        if(visited[curr]==0){
            dfs(list,curr,visited);
        }
    }
 }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int>visited(n,0);
        vector<vector<int>>list(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=j && isConnected[i][j]==1 &&(list[i].size()==0|| list[i].back()!=j  ) && (list[j].size()==0||list[j].back()!=i  ) ){
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(list,i,visited);
                count++;
            }
        }
        return count;
    }
};
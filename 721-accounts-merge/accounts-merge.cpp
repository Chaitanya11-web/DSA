class Solution {
public:
int findParent(int u,vector<int>&parent){
    if(u==parent[u])return u;
    parent[u]=findParent(parent[u],parent);
    return parent[u];
}
void rankByUnion(int u,int v,vector<int>&parent,vector<int>&rank){
int pu= findParent(u,parent);
int pv= findParent(v,parent);
if(rank[pu]<rank[pv]){
    parent[pu]=pv;
}
else if(rank[pu]>rank[pv]){
    parent[pv]=pu;
}
else{
    parent[pv]=pu;
    rank[pu]++; 
}
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int m=accounts.size();
        // int n=accounts[0].size();
        vector<int>parent(m);
        for(int i=0;i<m;i++){
            parent[i]=i;
        }
       vector<int>rank(m,0);
       unordered_map<string,int>map1;
     
       for(int i=0;i<m;i++){
        int n=accounts[i].size();
        for(int j=1;j<n;j++){
            string email=accounts[i][j];
            if(map1.find(email)!=map1.end()){
                rankByUnion(map1[email],i,parent,rank);
            }
            else{
                map1[email]=i;
            }
        }
       }
       unordered_map<int,vector<string>>merged;
       for(auto it:map1){
        string email=it.first;
        int index=it.second;
        int root=findParent(index,parent);
        merged[root].push_back(email);
       }
       vector<vector<string>>result(m);
       for(int i=0;i<m;i++){
    if(merged[i].empty()) continue;   // ⭐ FIX

    sort(merged[i].begin(), merged[i].end());
    result[i].push_back(accounts[i][0]);
    result[i].insert(
        result[i].end(),
        merged[i].begin(),
        merged[i].end()
    );
}vector<vector<string>> finalResult;
for (auto &v : result) {
    if (!v.empty()) {
        finalResult.push_back(v);
    }
}

return finalResult;
    }
};
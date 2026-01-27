class Solution {
public:
int findParent(int u,vector<int>&parent){
if(u==parent[u]){
    return u;
}
parent[u]=findParent(parent[u],parent);
return parent[u];
}
void rankByUnion(int u,int v,vector<int>&parent,vector<int>&rank){
    int pu=findParent(u,parent);
    int pv=findParent(v,parent);
if(rank[pu]>rank[pv]){
    parent[pv]=pu;
}
else if(rank[pu]<rank[pv]){
    parent[pu]=pv;
}
else{
    parent[pu]=pv;
    rank[pv]++; 
}
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        int numConn = connections.size();
        int cnt=0;
        if (numConn < n - 1) {
            return -1;
        }
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        queue<pair<int, int>> q;
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            q.push({u, v});
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            int u = p.first;
            int v = p.second;
            q.pop();
            if(findParent(u,parent)!=findParent(v,parent)){
             rankByUnion(u,v,parent,rank);
            }
            else{
                cnt++;
            }

        }
        int req=n-1;
        if(numConn>req){
            int extra=numConn-req;
            cnt=cnt-extra;
        }
        return cnt;
    }
};
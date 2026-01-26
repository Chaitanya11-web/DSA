class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>list(n);
        vector<int>dist(n,INT_MAX);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            list[u].push_back({v,wt});
        }
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src]=0;
        int steps=0;
        while(!q.empty() && steps<=k){
            int n=q.size();
            while(n--){
                auto it=q.front();
                int node=it.first;
                int wt=it.second;
                q.pop();
                for(int i=0;i<list[node].size();i++){
                    pair<int,int>p=list[node][i];
                    int adjnode=p.first;
                    int adjwt=p.second;
                    if(wt+adjwt<dist[adjnode]){
                        dist[adjnode]=wt+adjwt;
                        q.push({adjnode,wt+adjwt});
                    }
                }
            }
            steps++;
        }
       if(dist[dst]==INT_MAX){
        return -1;
       }
       else{
        return dist[dst];
       }
       return -1;
    }
};
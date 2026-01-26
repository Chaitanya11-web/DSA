class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> dist(n + 1, INT_MAX);
        set<pair<int,int>> st;

        // FIX 1: size n+1
        vector<vector<pair<int,int>>> list(n + 1);

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            list[u].push_back({wt, v});
        }

        st.insert({0, k});
        dist[k] = 0;

        while(!st.empty()){
            // FIX 2: copy before erase
            auto it = st.begin();
            int wt = it->first;
            int node = it->second;
            st.erase(it);

            for(int i = 0; i < list[node].size(); i++){
                int adjwt = list[node][i].first;
                int adjnode = list[node][i].second;

                if(wt + adjwt < dist[adjnode]){
                    if(dist[adjnode] != INT_MAX){
                        st.erase({dist[adjnode], adjnode});
                    }
                    dist[adjnode] = wt + adjwt;
                    st.insert({dist[adjnode], adjnode});
                }
            }
        }

        // FIX 3: correct indexing + unreachable check
        int maxTime = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n=numCourses;
      queue<int>q;
        vector<int>ans;
        vector<int>indegree(n,0);
        vector<vector<int>>list(n);
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            list[u].push_back(v);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<list[i].size();j++){
                int val=list[i][j];
                indegree[val]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
             ans.push_back(node); 
            q.pop();
            for(int i=0;i<list[node].size();i++){
                int curr=list[node][i];
                if(indegree[curr]==0){
                    q.push(curr);
                  
                }
                else if(indegree[curr]!=0){
                    indegree[curr]--;
                    if(indegree[curr]==0){
                    q.push(curr);
                  
                } 
                }
            }
        }
        int n1=ans.size();
        int i=0;int j=n1-1;
        while(i<j)
        {
            swap(ans[i],ans[j]);
            i++;
            j--;
        }
       if(ans.size()==n){
            return ans;
        }
        else{
            return {};
        }
        return ans;
    }
};
class Solution {
public:
  static bool myComparator(pair<int,int>p1,pair<int,int>p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    return p1.second<p2.second;
  }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>>map1;
        vector<vector<int>>res;
        int i=0;
        for(auto it:points){
            int u=it[0];
            int v=it[1];
            int ans=pow(u,2)+pow(v,2);
            map1.push_back({i,ans});
            i++;
        }
       
        sort(map1.begin(),map1.end(),myComparator);
       
   // return p1.first>p2.first;

        int j=0;
        for(auto it:map1){
            int f=it.first;
            if(j<k){
                res.push_back(points[f]);
                j++;
            }
        }
        return res;
    }
};
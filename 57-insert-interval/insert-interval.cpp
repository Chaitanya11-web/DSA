class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>>res;
       intervals.push_back(newInterval);
       sort(intervals.begin(),intervals.end());
 int n=intervals.size();
for(int i=0;i<n;i++){
    if(res.size()==0 ||res.back()[1]<intervals[i][0]){
        res.push_back(intervals[i]);
    }
    else{
        res.back()[1]=max(res.back()[1],intervals[i][1]);
    }
}

   return res; }
};
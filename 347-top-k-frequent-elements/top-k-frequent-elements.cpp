class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;
        
        unordered_map<int,int> map1;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int n = nums.size();
        
        for(int i=0;i<n;i++){
            map1[nums[i]]++;   // FIXED
        }  
        
        for(auto it:map1){
            
            int u = it.first;
            int v = it.second;
            
            pq.push({v,u});   // FIXED
            
            if(pq.size() > k)   // FIXED
                pq.pop();
        }
        
        while(!pq.empty()){
            
            res.push_back(pq.top().second);   // FIXED
            pq.pop();
        }

        return res;
    }
};

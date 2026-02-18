class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n = hand.size();
        
        if(n % groupSize != 0) return false;
        
        map<int,int> map1;
        
        for(int i=0;i<n;i++){
            map1[hand[i]]++;
        }
        
        while(!map1.empty()){
            
            int u = map1.begin()->first;  
            
            int k = groupSize;
            
            while(k--){
                
                if(map1.find(u) == map1.end())
                    return false;
                
                map1[u]--;
                
                if(map1[u] == 0)
                    map1.erase(u);
                
                u++;   
            }
        }
        
        return true;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int sum=0;
        vector<int>res;
        unordered_map<int,int>map1;
        for(int i=0;i<n;i++){
            if(map1.find(target-numbers[i])==map1.end()){
                map1.insert({numbers[i],i});
            }
            else{
                res.push_back(map1[target-numbers[i]]+1);
                res.push_back(i+1);
            }
        }
        return res;
    }
};
class Solution {
public:
vector<vector<int>>combine(vector<int>&candidates,int i,int n,int target,vector<int>&res,vector<vector<int>>&ans,set<vector<int>>&st){
    if(target==0){
       // sort(res.begin(),res.end());
        // if(st.find(res)==st.end()){

        //     st.insert(res);

        ans.push_back(res);
        return ans;
        
        
    }
    if(i==n ){
        return ans;

    }
    if(target<candidates[i]){
 combine(candidates,i+1,n,target-candidates[i],res,ans,st);
    }
    else{
        // if(j>i && candidates[j]==candidates[j-1]){
        //     continue;
        // }
        // if(candidates[j]>target){
        //     break;
        // }
        res.push_back(candidates[i]);
        combine(candidates,i+1,n,target-candidates[i],res,ans,st);
        res.pop_back();
        int j = i;
    while(j+1 < n && candidates[j] == candidates[j+1]){
        j++;
    }
         combine(candidates,j+1,n,target,res,ans,st);
    }
    return ans;
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        vector<vector<int>>ans;
        set<vector<int>>st;
       return  combine(candidates,0,n,target,res,ans,st);
    }
};
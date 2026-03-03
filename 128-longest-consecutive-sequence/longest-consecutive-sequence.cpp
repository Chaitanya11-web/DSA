class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int cnt=0;
        int x=0;
        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
for(auto it:st){
if(st.find(it-1)==st.end()){
    x=it;
    cnt=1;
    while(st.find(x+1)!=st.end()){
    x=x+1;
    cnt++;
}
maxi=max(maxi,cnt);
cnt=0;
}
}

  return maxi;  }
};
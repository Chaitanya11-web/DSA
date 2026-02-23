class Solution {
public:
    int candy(vector<int>& ratings) {
       int n=ratings.size();
       int cnt=0;
       vector<int>LtoR(n,1);
       vector<int>RtoL(n,1);
       vector<int>ans(n);
       for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
           LtoR[i]=LtoR[i-1]+1; 
        }

       } 
       for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            RtoL[i]=RtoL[i+1]+1;
        }
       }
       for(int i=0;i<n;i++){
        ans[i]=max(RtoL[i],LtoR[i]);
       }
       for(int i=0;i<n;i++){
        cnt+=ans[i];
       }
       return cnt;
    }
};
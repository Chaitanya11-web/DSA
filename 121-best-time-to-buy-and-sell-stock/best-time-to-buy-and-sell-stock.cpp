class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n=prices.size();
      int mini=prices[0] ;
      int profit=0;
      int cost=0;
      for(int i=0;i<n;i++){
        cost=prices[i]-mini;
        if(cost>profit){
            profit=cost;
        }
        if(mini>prices[i]){
mini=prices[i];
        }
      } 
      return profit;
    }
};
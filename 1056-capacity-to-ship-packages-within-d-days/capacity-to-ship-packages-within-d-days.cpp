class Solution {
public:
bool possible(vector<int>& weights, int mid, int days) {
        int load = 0;
        int dayCount = 1;  // Start with 1 day
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > mid) {
                dayCount++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=INT_MIN;
        int high=0;
        int ans=0;
        for(int i=0;i<n;i++){
      low=max(low,weights[i]);
      high+=weights[i];
      ans=high;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(weights,mid,days)){
                ans=mid;
high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
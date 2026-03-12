class Solution {
public:
int maxim(vector<int>& piles){
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
long long hours(vector<int>& piles,long long mid, int h){
    long long totalH=0;
    for(int i=0;i<piles.size();i++){
    totalH+=ceil((double)piles[i]/(double)mid);
    }
    return totalH;
}
    long long minEatingSpeed(vector<int>& piles, int h) {
        long long totalH=0;
        long long low=1;
        long long high=maxim(piles);
        while(low<=high){
            long long mid=low+(high-low)/2;
            totalH=hours(piles,mid,h);
            if(totalH<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
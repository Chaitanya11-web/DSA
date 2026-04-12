class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     int n=cardPoints.size();
     int l=0;
     int r=n-1;
     int sum=0;
     int maxSum=0;
     while(l<k){
sum+=cardPoints[l];
l++;
     
    }
    maxSum=max(sum,maxSum);
    l--;
    while(l>=0){
        sum-=cardPoints[l];
        l--;
        sum+=cardPoints[r];
        r--;
        maxSum=max(sum,maxSum);
    }

return maxSum;
    }
};
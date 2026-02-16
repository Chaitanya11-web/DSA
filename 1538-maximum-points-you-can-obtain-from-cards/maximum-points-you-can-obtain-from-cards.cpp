class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int l=0;
        int r=n-1;
        int sum=0;
        int maxSum=INT_MIN;
while(l<k){
    sum+=cardPoints[l];
    l++;

}
 maxSum=max(maxSum,sum);
l--;
while(l>=0){
    sum-=cardPoints[l];
    l--;
    sum+=cardPoints[r];
    r--;
    maxSum=max(maxSum,sum);
}
        return maxSum;
    }
};
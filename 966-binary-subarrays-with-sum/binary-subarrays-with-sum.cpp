class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int cnt2 = 0;
        int cnt1 = 0;
        while (j < n) {
            sum += nums[j];

            while (sum > goal) {
                if (nums[i] == 1) {
                    sum--;
                }
                i++;
            }
            cnt1 += j - i + 1;
            j++;
        }
        return cnt1;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
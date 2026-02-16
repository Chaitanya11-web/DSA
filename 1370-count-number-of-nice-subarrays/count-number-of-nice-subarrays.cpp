class Solution {
public:
 int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
       
        int cnt1 = 0;
        while (j < n) {
            sum += nums[j]%2;

            while (sum > goal) {
                if (nums[i]%2 == 1) {
                    sum--;
                }
                i++;
            }
            cnt1 += j - i + 1;
            j++;
        }
        return cnt1;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
         return atMost(nums, k) - atMost(nums, k - 1);
    }
};
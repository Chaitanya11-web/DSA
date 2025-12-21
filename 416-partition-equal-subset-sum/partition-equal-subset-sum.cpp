class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;

        int n = nums.size();
       
        for (int i : nums) {
            sum += i;
        }
         vector<vector<int>> t(n + 1, vector<int>(sum + 1, -1));
        int half = sum / 2;
        if (sum % 2 != 0) {
            return false;
        }

        else {

            for (int i = 0; i < n + 1; i++) {
                for (int j = 0; j < half + 1; j++) {
                    if (i == 0 || j == 0) {
                        t[i][j] = 0;
                    } 
                    else if (j < nums[i - 1]) {
                        t[i][j] = t[i - 1][j];
                    } else {
                        t[i][j] = max(t[i - 1][j],
                                      nums[i - 1] + t[i - 1][j - nums[i-1]]);
                    }
                }
            }
        }
        if (t[n][half] == half) {
            return true;
        } else {
            return false;
        }
        return false;
    }
};
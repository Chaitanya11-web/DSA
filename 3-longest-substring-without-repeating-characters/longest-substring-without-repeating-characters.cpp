class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);   // stores last index
        int i = 0, j = 0;
        int maxLen = 0;
        int n = s.length();

        while (j < n) {
            // if character already seen inside window
            if (hash[s[j]] >= i) {
                i = hash[s[j]] + 1;
            }

            hash[s[j]] = j;  // update last index
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};

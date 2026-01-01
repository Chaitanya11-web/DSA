class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        
        // Step 1: Count frequency
        for(char c : s) {
            freq[c]++;
        }

        int length = 0;
        bool oddFound = false;

        // Step 2: Build palindrome length
        for(auto it : freq) {
            if(it.second % 2 == 0) {
                length += it.second;
            } else {
                length += it.second - 1;
                oddFound = true;
            }
        }

        // Step 3: One odd char allowed in center
        if(oddFound) length++;

        return length;
    }
};

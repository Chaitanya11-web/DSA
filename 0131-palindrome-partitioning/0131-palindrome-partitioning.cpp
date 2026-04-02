class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void partitionHelper(int start, string &s, vector<string> &path, vector<vector<string>> &result) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                partitionHelper(i+ 1, s, path, result);
                path.pop_back();  // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        partitionHelper(0, s, path, result);
        return result;
    }
};

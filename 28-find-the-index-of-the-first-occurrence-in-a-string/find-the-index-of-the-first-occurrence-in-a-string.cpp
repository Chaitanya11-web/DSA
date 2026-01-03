class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        if (n == 0) return 0;

        // ---------- LPS ARRAY ----------
        vector<int> arr(n, 0);
        int pre = 0, suff = 1;

        while (suff < n) {
            if (needle[pre] == needle[suff]) {
                arr[suff] = pre + 1;
                pre++;
                suff++;
            } else {
                if (pre != 0) {
                    pre = arr[pre - 1];
                } else {
                    suff++;
                }
            }
        }

        // ---------- MATCHING ----------
        int i = 0, j = 0;
        int m = haystack.length();

        while (i < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == n) {
                return i - j;   // match found
            }

            else if (i < m && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = arr[j - 1];   // ✅ CORRECT FALLBACK
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};

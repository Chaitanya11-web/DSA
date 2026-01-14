class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        int count = 0, maxV = 0;

        while (j < k) {
            if (s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u') {
                count++;
            }
            maxV = max(maxV, count);
            j++;
        }

        while (j < n) {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
                count--;
            }
            i++;

            if (s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u') {
                count++;
            }
            maxV = max(maxV, count);
            j++;
        }

        return maxV;   // ✅ guaranteed return
    }
};

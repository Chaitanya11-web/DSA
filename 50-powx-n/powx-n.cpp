class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;      // 🟢 FIX: promote to long long
        double ans = 1;

        if (N < 0) {
            x = 1 / x;
            N = -N;           // 🟢 SAFE now
        }

        while (N > 0) {
            if (N % 2 == 1) {
                ans = ans * x;
                N = N - 1;
            } else {
                N = N / 2;
                x = x * x;
            }
        }

        return ans;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;      
        double ans = 1;

        if (N < 0) {
            x = 1 / x;
            N = -N;           
        }

        while (N > 0) {
            if(N%2==1){
                //last me x=1 hojaayega ya no. odd hoga to
 ans=ans*x;
N=N-1;
            }
            else{
                //ye yaad rakhni h trick like x=2,n=8
                N=N/2;
                x=x*x;
            }
          
        }

        return ans;
    }
};

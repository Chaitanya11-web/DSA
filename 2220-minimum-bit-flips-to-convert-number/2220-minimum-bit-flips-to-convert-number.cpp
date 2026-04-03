class Solution {
public:
    int minBitFlips(int start, int goal) {
      int ans=0;
      ans=start^goal;
      int n=ans;
      int cnt=0;
      while(n!=0){
cnt+=n&1;
n=n>>1;
      }
      return cnt;  
    }
};
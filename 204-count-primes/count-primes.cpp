class Solution {
public:
    int countPrimes(int n) {
      vector<bool>isPrime(n+1,1);
      isPrime[0]=0;
      isPrime[1]=0;
      
      int cnt=0;
      for(int i=2;i<n;i++){
        if(isPrime[i]==1){
            for(int j=i*2;j<n;j+=i){
                isPrime[j]=0;
            }
        }
      }
      isPrime[2]=0;
      for(int i=0;i<n+1;i++){
        if(isPrime[i]==1){
            cnt++;
        }
      }  
      return cnt;
    }
};
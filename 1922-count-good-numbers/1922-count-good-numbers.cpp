class Solution {
public:
long long pow(long long x,long long b){
    int M= 1e9+7;
long long res=1;
while(b>0){
if(b%2==1){
    res=(res*x)%M;
    b--;
    }
    else{
        x=(x*x)%M;
        b=b/2;
    }
}
return int(res);
}
    int countGoodNumbers(long long n) {
         int M= 1e9+7;
      return (pow(4,n/2)*pow(5,((n+1)/2)))%M;  
    }
};
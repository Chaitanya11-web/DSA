class Solution {
public:
long long pow(long long x,long long b){
    int M= 1e9+7;
long long res=1;
//error
while(b>0){
if(b%2==1){
    res=(res*x)%M;
    //error
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
       // ye hamesha modeule karte hue int me ho
       //agar isko int me nhi loge to ye ho jayega long long% double which is wrong 
       //else ye hoga long long %int which is correct
         int M= 1e9+7;
         //n/2 even place par 4 ko multiply karenge
         
         //n+1/2 odd place par 5 ko multiply karenge

      return (pow(4,n/2)*pow(5,((n+1)/2)))%M;  
    }
};
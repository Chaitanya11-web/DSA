class Solution {
public:
    string intToRoman(int num) {
      vector<string>roman={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
      vector<int>values={1,4,5,9,10,40,50,90,100,400,500,900,1000}  ;
      string res;
      int i=12;
      while(num>0){
if(values[i]<=num){
    num-=values[i];
    res+=roman[i];
}
else{
    i--;
}
      }
   return res; }
};
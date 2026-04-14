class Solution {
public:
    string largestOddNumber(string num) {
       int n=num.size();
       int i=0;
       for( i=n-1;i>=0;i--){
        if(num[i]%2==1){
            break;
        }
       } 
       //i+1 isliye kyuki kyuki vo index se bhar aa jayenge aur indexing 0 based hoti h
       return num.substr(0,i+1);
    }
};
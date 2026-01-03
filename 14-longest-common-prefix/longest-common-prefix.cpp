class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res;
        char sample;
     int i=0;
     int j=0;
     int k=0;
      bool ans =false;
     int mini=strs[0].length();
     int n1=0;
     for(k=0;k<n;k++){
n1=strs[k].length();
if(n1<mini){
    mini=n1;
}
     }
     while(i<mini){
       sample=strs[0][i];
        for(int j=0;j<n;j++){
              
           
            if(sample==strs[j][i]){
                ans=true;
            }
            else{
                ans=false;
                break;
            }
        }
      
        if(ans==true){
            res+=sample;
        }
        else{
            break;
        }
        i++;
     }
     ans=false;
      return res;
    }
};
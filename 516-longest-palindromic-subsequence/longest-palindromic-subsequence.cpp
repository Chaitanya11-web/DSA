class Solution {
public:
    int longestPalindromeSubseq(string s) {
       int n=s.length();
        int m=s.length();
        string str=s;
        reverse(str.begin(),str.end()); 
       
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==str[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
      return t[m][n];   
    }
};
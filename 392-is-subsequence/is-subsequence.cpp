class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<int>>t1(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++){
            for (int j=1;j<n+1;j++){
                if(s[i-1]==t[j-1]){
                    t1[i][j]=1+t1[i-1][j-1];
                }
                else{
                    t1[i][j]=max(t1[i-1][j],t1[i][j-1]);
                }
            }
        }
        if(t1[m][n]==m){
            return true;
        }
        else{
            return false;
        }
        return false;
    }
};
class Solution {
public:
string scs(string str1, string str2,int i,int j,string ans,vector<vector<int>>&t){
if(i==0 || j==0){
    return ans;
}
while(i>0 && j>0){
    if(str1[i-1]==str2[j-1]){
        ans+=str1[i-1];
        i--;
        j--;
    }
    else{
        if(t[i-1][j]>t[i][j-1]){
            ans+=str1[i-1];
            
            i--;
        }
        else {
            ans+=str2[j-1];
               
            j--;
        }
    }
}
 while(i>0){
        ans+=str1[i-1];
        i--;
    }

    while(j>0){
        ans+=str2[j-1];
        j--;
    }
return ans;
}
    string shortestCommonSupersequence(string str1, string str2) {
       int m=str1.length();
       int n=str2.length();
       string ans;
       vector<vector<int>>t(m+1,vector<int>(n+1,0));
       for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(str1[i-1]==str2[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
       }
       
      ans= scs( str1,  str2, m, n,ans,t);
      reverse(ans.begin(),ans.end());
       return ans; 
    }
};
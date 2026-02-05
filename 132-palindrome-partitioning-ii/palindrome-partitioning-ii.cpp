class Solution {
public:
    int minCut(string s) {
        
        int n = s.size();
        
        vector<int> cuts(n);
        vector<vector<bool>> pal(n, vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            
            cuts[i] = i;  // worst case
            
            for(int j=0;j<=i;j++){
                
                // palindrome check
                if(s[i]==s[j] && (i-j<=2 || pal[j+1][i-1])){
                    
                    pal[j][i] = true;
                    
                    if(j==0)
                        cuts[i] = 0;
                    else
                        cuts[i] = min(cuts[i], cuts[j-1]+1);
                }
            }
        }
        
        return cuts[n-1];
    }
};

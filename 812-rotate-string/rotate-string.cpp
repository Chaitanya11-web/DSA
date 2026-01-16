class Solution {
public:
    bool rotateString(string s, string goal) {
        int i = 0;
        int j = 0;
        if(goal.length()!=s.length())return false;
        string str=s+s;
        int m = s.length()+s.length();
        int n = goal.length();
        bool ans = true;
       while(i<m && j<n){
        if(str[i]!=goal[j]){
            ans=false;
            i++;
            if(j==n-1 || i==m-1){
                return false;
            }
        }
        else{
            ans=true;
            i++;
            j++;
        }
       }
        return ans;
    }
};
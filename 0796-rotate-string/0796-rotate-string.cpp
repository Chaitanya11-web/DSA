class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.length()!=s.length())return false;
        string str=s+s;
        int m=str.length();
        int n=goal.length();
        int i=0;
        while(i<n){
            if(str.substr(i,n)==goal){
                return true;
            }
            i++;
        }
        return false;
    }
};
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(s.begin(),s.end());
       sort(g.begin(),g.end());
       int i=0;
       int count=0;
       int j=0;
       int m=s.size();
       int n=g.size();
       while(i<m && j<n){
        if(s[i]>=g[j]){
            i++;
            j++;
            count++;
        }
        else{
        i++;}
       } 
       return count;
    }
};
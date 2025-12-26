class Solution {
public:
    string longestPrefix(string s) {
       int n=s.length();
        vector<int>arr(n,0);
        int pre=0;
        int suff=1;
        while(pre<n && suff<n){
            if(s[pre]==s[suff]){
                arr[suff]=pre+1;
                pre++;
                suff++;
            }
            else{
               while(pre>0){
                   pre--;
                   if(s[arr[pre]]==s[suff]){
                       pre=arr[pre];
                      arr[suff]=pre+1;
                pre++;
                suff++;
                break;
                   }
               }
              if(pre==0)suff++; 
            }
        }
        int n1= arr[n-1]; 
        string res;
        for(int i=0;i<n1;i++){
          res+=s[i]; 
        }
        return res;
    }
};
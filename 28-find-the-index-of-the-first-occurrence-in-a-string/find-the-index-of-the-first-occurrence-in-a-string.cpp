class Solution {
public:
    int strStr(string haystack, string needle) {
     int n1=0;
     int h1=0;
     int pos=0;
     int i=0;
     while(i<haystack.length()){
        if(haystack[i]==needle[n1]){
            i++;
            n1++;
            if(n1==needle.length()){
                return i-n1;
            }
        }
        else{
pos++;
i=pos;
n1=0;
        }
     }
     return -1;   
    }
};
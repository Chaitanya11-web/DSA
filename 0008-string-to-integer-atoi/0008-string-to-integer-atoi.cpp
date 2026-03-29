class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        int sign=1;
        while(i<n && s[i]==' '){
            i++;
        }
        //error operator precedence
        if(i<n && (s[i]=='+'|| s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            //error
            i++;
        }
        long result=0;
        while(i<n && isdigit(s[i])){
            int num=s[i]-'0';
            result=result*10+num;
            if(sign*result>INT_MAX)return INT_MAX;
            if(sign*result<INT_MIN)return INT_MIN;
            i++;
           
        }
         
        return (int)(sign*result);
    }
};
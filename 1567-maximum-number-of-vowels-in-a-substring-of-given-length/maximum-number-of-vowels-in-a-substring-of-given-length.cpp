class Solution {
public:
bool isVowel(char ch)
{
    if(ch=='a'|| ch=='e'|| ch=='i'||ch=='o'||ch=='u'){
        return true;
    }
    return false;
}    int maxVowels(string s, int k) {
       int n=s.length();
       int i=0;
       int j=0;
       int maxCnt=INT_MIN;
       int cnt=0;
       while(j<n){
if(isVowel(s[j])){
cnt++;
}
if(j-i+1==k){
    maxCnt=max(maxCnt,cnt);
    if(isVowel(s[i])){
        cnt--;
      
    }
      i++;
}

    j++;   } 
    return maxCnt;
    }
};
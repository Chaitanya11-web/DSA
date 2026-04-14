class Solution {
public:
bool isVowel(char ch){
    if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u'){
        return true;
    }
    return false;
}
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        int cnt=0;
        int res=INT_MIN;
//         Every sliding window problem has 3 steps — in this ORDER:

// 1. EXPAND  →  add nums[j] to window
// 2. SHRINK  →  fix window if it violated constraint  
// 3. MEASURE →  record answer ← THIS IS ALWAYS LAST, ALWAYS OUTSIDE
        while(j<n){
if(isVowel(s[j])){
cnt++;

}
if(j-i+1>k){
if(isVowel(s[i])){
    cnt--;
}
i++;
}
res=max(res,cnt);
            j++;
        }
        return res;
    }
};
class Solution {
public:
vector<string>solve(string& digits,int i,string& temp,vector<string>&ans,unordered_map<char,string>&map1){
    if(i>=digits.length()){
ans.push_back(temp);
return ans;
    }
    char ch=digits[i];
    string str=map1[ch];

    for(int j=0;j<str.length();j++){
        temp.push_back(str[j]);
         solve(digits,i+1,temp,ans,map1);
         temp.pop_back();
    }
return ans;
}
    vector<string> letterCombinations(string digits) {
       string temp;
       vector<string>ans;
       unordered_map<char,string>map1;
    map1['2']="abc";
    map1['3']="def";
    map1['4']="ghi";
    map1['5']="jkl";
    map1['6']="mno";
    map1['7']="pqrs";
    map1['8']="tuv";
    map1['9']="wxyz";
    return solve(digits,0,temp,ans,map1);
    }
};
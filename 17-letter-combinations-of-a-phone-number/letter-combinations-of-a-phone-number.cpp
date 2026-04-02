class Solution {
public:

void solve(string& digits, int i, int j, string& temp,
           vector<string>& ans, vector<string>& mapping){

    // ❌ no more digits
    if(i == digits.size()){
        if(temp.size() == digits.size()){
            ans.push_back(temp);
        }
        return;
    }

    int num = digits[i] - '0';
    string letters = mapping[num];

    // ❌ no more letters for this digit
    if(j == letters.size()){
        return;
    }

    // ✅ INCLUDE this letter
    temp.push_back(letters[j]);
    solve(digits, i+1, 0, temp, ans, mapping);
    temp.pop_back();

    // ✅ EXCLUDE this letter → try next letter
    solve(digits, i, j+1, temp, ans, mapping);
}

vector<string> letterCombinations(string digits) {

   // if(digits.empty()) return {};

    vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> ans;
    string temp;

    solve(digits, 0, 0, temp, ans, mapping);

    return ans;
}
};
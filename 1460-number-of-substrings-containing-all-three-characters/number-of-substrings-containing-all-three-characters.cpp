class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        unordered_map<int,int>map1;
        int i=0;
        int j=0;
        while(j<n){
            map1[s[j]]++;
            while(map1.size()==3){
                map1[s[i]]--;
                if(map1[s[i]]==0){
                    map1.erase(s[i]);
                     
                }
                i++;
               cnt+=n-j;
            }
            
            j++;
        }
        return cnt;

    }
};